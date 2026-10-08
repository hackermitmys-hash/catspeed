#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int n) {
    printf("Array Elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main() {
    int n, i, pos, elem, choice;
    int *arr = NULL;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input elements
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);
    }

    do {
        printf("\nChoose operation:\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;

            case 2:
                printf("Enter position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                    break;
                }
                printf("Enter element to insert: ");
                scanf("%d", &elem);
                arr = (int *)realloc(arr, (n + 1) * sizeof(int));
                for (i = n; i >= pos; i--) {
                    *(arr + i) = *(arr + i - 1);
                }
                *(arr + pos - 1) = elem;
                n++;
                display(arr, n);
                break;

            case 3:
                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }
                for (i = pos - 1; i < n - 1; i++) {
                    *(arr + i) = *(arr + i + 1);
                }
                arr = (int *)realloc(arr, (n - 1) * sizeof(int));
                n--;
                display(arr, n);
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &elem);
                for (i = 0; i < n; i++) {
                    if (*(arr + i) == elem) {
                        printf("Element %d found at position %d\n", elem, i + 1);
                        break;
                    }
                }
                if (i == n) {
                    printf("Element %d not found\n", elem);
                }
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    free(arr);
    return 0;
}