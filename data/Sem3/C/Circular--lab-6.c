#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5   // maximum size of the circular queue

 struct Call {
    int callID;        // or any identifier
    char callerName[50];
    // You can add more fields (e.g. time of arrival, priority, etc.)
};

struct Call queueArr[MAX];
int front = -1;
int rear = -1;

// Utility to check empty
int isEmpty() {
    return (front == -1);
}

// Utility to check full
int isFull() {
    // Next position of rear in circular fashion equals front
    return ((rear + 1) % MAX == front);
}

// a. Add a call (enqueue)
void addCall(struct Call c) {
    if (isFull()) {
        printf("Queue Overflow! Cannot add call (ID=%d, Name=%s)\n", c.callID, c.callerName);
        return;
    }
    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queueArr[rear] = c;
    printf("Added call: ID=%d, Name=%s at position %d\n", c.callID, c.callerName, rear);
}

// b. Delete a call (dequeue)
void deleteCall() {
    if (isEmpty()) {
        printf("Queue Underflow! No calls to service.\n");
        return;
    }
    struct Call c = queueArr[front];
    printf("Serving (Deleting) call: ID=%d, Name=%s from position %d\n", c.callID, c.callerName, front);

    if (front == rear) {
        // only one element
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// c. Display current status of calls
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty — no waiting calls.\n");
        return;
    }

    printf("Current waiting calls (front = %d, rear = %d):\n", front, rear);
    int i = front;
    while (1) {
        printf("  Position %d → ID=%d, Name=%s\n", i, queueArr[i].callID, queueArr[i].callerName);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
}

// Helper: to read a call’s data
struct Call inputCall() {
    struct Call c;
    printf("Enter Call ID (integer): ");
    scanf("%d", &c.callID);
    printf("Enter Caller Name: ");
    // consume newline if needed
    getchar();
    fgets(c.callerName, sizeof(c.callerName), stdin);
    // remove trailing newline
    size_t len = strlen(c.callerName);
    if (len > 0 && c.callerName[len - 1] == '\n') {
        c.callerName[len - 1] = '\0';
    }
    return c;
}

// Menu-driven interface
int main() {
    int choice;
    while (1) {
        printf("\n=== Call Center Simulation Menu ===\n");
        printf("1. Add a call\n");
        printf("2. Delete (service) a call\n");
        printf("3. Display current calls\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        switch (choice) {
            case 1: {
                struct Call c = inputCall();
                addCall(c);
                break;
            }
            case 2:
                deleteCall();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}