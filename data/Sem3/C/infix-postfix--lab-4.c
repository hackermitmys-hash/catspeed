#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = c;  // FIXED: push using ++top
    }
}

// Pop operation
char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

// Peek operation
char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

// Precedence of operators
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Convert infix to postfix
void intopos(char infix[]) {
    char postfix[MAX];
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            pop();  // Remove '('
        } else {
            while (precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

// Main function
int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    intopos(infix);

    return 0;
}