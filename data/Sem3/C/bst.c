/*    Dictionary can be implemented using binary search tree. A binary search tree is a binary tree such that each node stores a key of a dictionary. Key 'k' of a node is always greater than the keys present in its left sub tree. Similarly, key 'k' of a node is always lesser than the keys present in its right sub tree. Design, Develop and Implement a menu driven Program in C to perform the following operations using Binary Search Tree (BST).
a. Create a dictionary of words
b. Traverse the dictionary in Inorder, Preorder and Post Order
c. Search the dictionary for a given word (KEY) and display the appropriate message    */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN    50
#define MAX_MEANING_LEN 100

typedef struct Node {
    char word[MAX_WORD_LEN];
    char meaning[MAX_MEANING_LEN];
    struct Node *left;
    struct Node *right;
} Node;

// Declare root as a global variable
Node *root = NULL;

// Function prototypes
Node* createNode(const char *word, const char *meaning);
Node* insertNode(Node *node, const char *word, const char *meaning);
void inorderTraversal(Node *node);
void preorderTraversal(Node *node);
void postorderTraversal(Node *node);
Node* searchNode(Node *node, const char *word);

int main() {
    int choice;
    char w[MAX_WORD_LEN];
    char m[MAX_MEANING_LEN];
    Node *found = NULL;

    do {
        printf("\n--- Dictionary using BST ---\n");
        printf("1. Insert word\n");
        printf("2. Traverse Inorder\n");
        printf("3. Traverse Preorder\n");
        printf("4. Traverse Postorder\n");
        printf("5. Search for a word\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s",w);
                w[strcspn(w, "\n")] = '\0';
                printf("Enter meaning: ");
                scanf("%s",m);
                m[strcspn(m, "\n")] = '\0';
                root = insertNode(root, w, m);  // use global root
                break;

            case 2:
                printf("\nInorder traversal:\n");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("\nPreorder traversal:\n");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("\nPostorder traversal:\n");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Enter word to search: ");
                scanf("%s",w);
                w[strcspn(w, "\n")] = '\0';
                found = searchNode(root, w);
                if (found) {
                    printf("Word found: %s\nMeaning: %s\n", found->word, found->meaning);
                } else {
                    printf("Word '%s' not found in dictionary.\n", w);
                }
                break;

            case 0:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

Node* createNode(const char *word, const char *meaning) {
    Node *temp = (Node*)malloc(sizeof(Node));
    if (temp==NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strncpy(temp->word, word, MAX_WORD_LEN);
    temp->word[MAX_WORD_LEN-1] = '\0';
    strncpy(temp->meaning, meaning, MAX_MEANING_LEN);
    temp->meaning[MAX_MEANING_LEN-1] = '\0';
    temp->left = temp->right = NULL;
    return temp;
}

Node* insertNode(Node *node, const char *word, const char *meaning) {
    if (node == NULL) {
        return createNode(word, meaning);
    }
    int cmp = strcmp(word, node->word);
    if (cmp < 0) {
        node->left = insertNode(node->left, word, meaning);
    } else if (cmp > 0) {
        node->right = insertNode(node->right, word, meaning);
    } else {
        // word already exists — update meaning
        printf("Word '%s' already exists. \n", word);
       
    }
    return node;
}

void inorderTraversal(Node *node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%s : %s\n", node->word, node->meaning);
        inorderTraversal(node->right);
    }
}

void preorderTraversal(Node *node) {
    if (node != NULL) {
        printf("%s : %s\n", node->word, node->meaning);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void postorderTraversal(Node *node) {
    if (node != NULL) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        printf("%s : %s\n", node->word, node->meaning);
    }
}

Node* searchNode(Node *node, const char *word) {
    if (node == NULL) {
        return NULL;
    }
    int cmp = strcmp(word, node->word);
    if (cmp == 0) {
        return node;
    } else if (cmp < 0) {
        return searchNode(node->left, word);
    } else {
        return searchNode(node->right, word);
    }
}

