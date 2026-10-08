#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[256];
    struct Node *prev, *next;
} Node;

Node *cur = NULL;

Node *mk(const char *url) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (!n) exit(1);
    strcpy(n->url, url);
    n->prev = n->next = NULL;
    return n;
}

void visit(const char *url) {
    Node *n = mk(url);
    if (cur) {
        // discard forward history
        Node *t = cur->next;
        while (t) {
            Node *x = t;
            t = t->next;
            free(x);
        }
        cur->next = n;
        n->prev = cur;
    }
    cur = n;
    printf("Visited: %s\n", url);
}

void backSteps(int k) {
    int i = 0;
    while (i < k && cur && cur->prev) {
        cur = cur->prev;
        i++;
    }
    printf("Back %d step(s): %s\n", i, cur ? cur->url : "None");
}

void forwardSteps(int k) {
    int i = 0;
    while (i < k && cur && cur->next) {
        cur = cur->next;
        i++;
    }
    printf("Forward %d step(s): %s\n", i, cur ? cur->url : "None");
}

void showHistory() {
    if (!cur) {
        printf("No history.\n");
        return;
    }
    // go to first
    Node *h = cur;
    while (h->prev) h = h->prev;
    printf("History:\n");
    while (h) {
        printf("  %s%s\n", h->url, h==cur ? "  <- current" : "");
        h = h->next;
    }
}

int main() {
    int ch, k;
    char url[256];
    for (;;) {
        printf("\n1=Visit  2=Back  3=Forward  4=Show  5=Exit\nChoice: ");
        if (scanf("%d", &ch)!=1) break;
        switch(ch) {
        case 1:
            printf("URL: ");
            scanf("%s", url);
            visit(url);
            break;
        case 2:
            printf("Steps back: ");
            scanf("%d", &k);
            backSteps(k);
            break;
        case 3:
            printf("Steps forward: ");
            scanf("%d", &k);
            forwardSteps(k);
            break;
        case 4:
            showHistory();
            break;
        case 5:
            printf("Exiting...\n");
            // free all
            {
                Node *h = cur;
                if (h) {
                    while (h->prev) h = h->prev;
                    while (h) {
                        Node *x = h->next;
                        free(h);
                        h = x;
                    }
                }
            }
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
