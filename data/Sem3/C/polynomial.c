/*   Design, Develop and Implement a Program in C for the following operations on Singly Circular Linked List (SCLL) with header nodes
a. Represent a Polynomial of the form P(x,y,z) = 6x2 y 2 z-4 yz5 +3x3 yz+2xy5 z-2xyz3
b. Evaluate the polynomial  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Term {
    int coeff;
    int exp_x;
    int exp_y;
    int exp_z;
    struct Term *next;
} Term;

// Declare header as a global variable
Term *header = NULL;

// Function to create/initialise the header node
void initHeader() {
    header = (Term*) malloc(sizeof(Term));
    if (!header) {
        printf("Memory allocation failed for header\n");
        exit(EXIT_FAILURE);
    }
    header->next = header;  // circular: points to itself when list empty
}

// Insert a term at end (before header)
void insertTerm(int coeff, int exp_x, int exp_y, int exp_z) {
    Term* newNode = (Term*) malloc(sizeof(Term));
    if (!newNode) {
        printf("Memory allocation failed for new node\n");
        exit(EXIT_FAILURE);
    }
    newNode->coeff = coeff;
    newNode->exp_x  = exp_x;
    newNode->exp_y  = exp_y;
    newNode->exp_z  = exp_z;

    // If list empty, header->next == header
    Term* cur = header;
    while (cur->next != header) {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->next = header;
}

// Display the polynomial
void displayPolynomial() {
    Term* cur = header->next;
    if (cur == header) {
        printf("0\n");
        return;
    }
    int first = 1;
    while (cur != header) {
        if (!first) {
            if (cur->coeff >= 0) printf(" + ");
            else printf(" - ");
        } else {
            if (cur->coeff < 0) printf("-");
            first = 0;
        }
        int absCoeff = (cur->coeff < 0 ? -cur->coeff : cur->coeff);
        if (absCoeff != 1 ||
            (cur->exp_x == 0 && cur->exp_y == 0 && cur->exp_z == 0)) {
            printf("%d", absCoeff);
        }
        if (cur->exp_x != 0) {
            printf("x");
            if (cur->exp_x != 1) printf("^%d", cur->exp_x);
        }
        if (cur->exp_y != 0) {
            printf("y");
            if (cur->exp_y != 1) printf("^%d", cur->exp_y);
        }
        if (cur->exp_z != 0) {
            printf("z");
            if (cur->exp_z != 1) printf("^%d", cur->exp_z);
        }
        cur = cur->next;
    }
    printf("\n");
}

// Evaluate the polynomial for given x, y, z
double evaluatePolynomial(double x, double y, double z) {
    Term* cur = header->next;
    double sum = 0.0;
    while (cur != header) {
        double termVal = cur->coeff *
                         pow(x, cur->exp_x) *
                         pow(y, cur->exp_y) *
                         pow(z, cur->exp_z);
        sum += termVal;
        cur = cur->next;
    }
    return sum;
}

// Free all nodes including header
void freePolynomial() {
    Term* cur = header->next;
    while (cur != header) {
        Term* temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(header);
    header = NULL;
}

int main() {
    // Initialise header
    initHeader();

    // Insert the terms of P(x, y, z) = 6x^2 y^2 z - 4 y z^5 + 3 x^3 y z + 2 x y^5 z - 2 x y z^3
    insertTerm(6,  2, 2, 1);
    insertTerm(-4, 0, 1, 5);
    insertTerm(3,  3, 1, 1);
    insertTerm(2,  1, 5, 1);
    insertTerm(-2, 1, 1, 3);

    printf("Polynomial P(x,y,z) = ");
    displayPolynomial();

    double x_val, y_val, z_val;
    printf("Enter values for x, y, z (space-separated): ");
    scanf("%lf %lf %lf", &x_val, &y_val, &z_val);

    double result = evaluatePolynomial(x_val, y_val, z_val);
    printf("P(%.2f, %.2f, %.2f) = %.4f\n", x_val, y_val, z_val, result);

    freePolynomial();
    return 0;
}
