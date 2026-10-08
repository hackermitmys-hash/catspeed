#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5   // Maximum size of stack

// Define Book structure
typedef struct {
    char ISBN[20];
    char Title[50];
    char Author[50];
    float Price;
} BOOK;

// Stack
BOOK stack[MAX];
int top = -1;

// Function prototypes
void push();
void pop();
void display();

int main() {
    int choice;

    printf("Book Stack Implementation (Max Size = %d)\n", MAX);

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. PUSH (Add Book)\n");
        printf("2. POP (Remove Book)\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// PUSH operation
void push() {
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot add more books.\n");
        return;
    }
    BOOK b;
    printf("Enter ISBN: ");
    fgets(b.ISBN, sizeof(b.ISBN), stdin);
    b.ISBN[strcspn(b.ISBN, "\n")] = '\0';

    printf("Enter Title: ");
    fgets(b.Title, sizeof(b.Title), stdin);
    b.Title[strcspn(b.Title, "\n")] = '\0';

    printf("Enter Author: ");
    fgets(b.Author, sizeof(b.Author), stdin);
    b.Author[strcspn(b.Author, "\n")] = '\0';

    printf("Enter Price: ");
    scanf("%f", &b.Price);
    getchar();

    stack[++top] = b;
    printf("\nBook pushed successfully.\n");
}

// POP operation
void pop() {
    if (top == -1) {
        printf("\nStack Underflow! No books to remove.\n");
        return;
    }
    BOOK b = stack[top--];
    printf("\nPopped Book Details:\n");
    printf("ISBN: %s | Title: %s | Author: %s | Price: %.2f\n",
           b.ISBN, b.Title, b.Author, b.Price);
}

// Display Stack
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
        return;
    }
    printf("\nBooks in Stack (Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("[%d] ISBN: %s | Title: %s | Author: %s | Price: %.2f\n",
               i, stack[i].ISBN, stack[i].Title, stack[i].Author, stack[i].Price);
    }
}