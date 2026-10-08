#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char song[100];
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->song, name);
    newNode->next = NULL;
    return newNode;
}

void addSong() {
    char name[100];
    printf("Enter song name: ");
    scanf(" %[^\n]", name);
    Node* newNode = createNode(name);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Added: %s\n", name);
}

void playStart() {
    if (!head) {
        printf("No songs in the list.\n");
        return;
    }
    Node* temp = head;
    printf("Playing songs:\n");
    while (temp) {
        printf("%s\n", temp->song);
        temp = temp->next;
    }
    free(temp);
}

void playEndRec(Node* node) {
    if (!node) return;
    playEndRec(node->next);
    printf("%s\n", node->song);
}

void playEnd() {
    if (!head) {
        printf("No songs in the list.\n");
        return;
    }
    printf("Playing songs in reverse order:\n");
    playEndRec(head);
}

void delStart() {
    if (!head) {
        printf("No songs to delete.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    printf("Deleted: %s\n", temp->song);
    free(temp);
}

void delEnd() {
    if (!head) {
        printf("No songs to delete.\n");
        return;
    }
    if (!head->next) {
        printf("Deleted: %s\n", head->song);
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->next) {
        temp = temp->next;
    }
    printf("Deleted: %s\n", temp->next->song);
    free(temp->next);
    temp->next = NULL;
}

void menu(){
    printf("Menu:\n");
    printf("1. Add Song\n");
    printf("2. Play from Start\n");
    printf("3. Play from End\n");
    printf("4. Delete from Start\n");
    printf("5. Delete from End\n");
    printf("6. Exit\n");
}

int main(){
    int choice;
    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addSong(); break;
            case 2: playStart(); break;
            case 3: playEnd(); break;
            case 4: delStart(); break;
            case 5: delEnd(); break;
            case 6: exit(0);
            default: printf("Invalid choice.\n");
        }
        printf("\n");
    }
    return 0;
}