#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

// Declare the printData function before using it.
void printData(struct Node* pntr);

void insert(struct Node* pntr, int p, int q) {
    struct Node* current = pntr;
    while (current->next != NULL) {
        current = current->next;
    }
    struct Node* pLoc = (struct Node*)malloc(sizeof(struct Node));
    current->next = pLoc;
    pLoc->data = p;
    struct Node* qLoc = (struct Node*)malloc(sizeof(struct Node));
    pLoc->next = qLoc;
    qLoc->data = q;
    qLoc->next = NULL;

    printf("Inserted nodes with values %d and %d.\n", p, q);
    printf("List after insertion: ");
    printData(pntr); // Print the list after insertion
}

void replaceByZero(struct Node* pntr, int p, int q) {
    while (pntr != NULL) {
        if (pntr->data / p == q) {
            pntr->data = 0;
            printf("Replaced node data with 0 where data / %d == %d.\n", p, q);
            break; // Add a break to exit the loop after replacement
        }
        pntr = pntr->next;
    }
}

void operations(struct Node* pntr) {
    insert(pntr, 7, 4);
    replaceByZero(pntr, 7, 4);
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 3;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 5;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 7;
    head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->data = -8;
    head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 34;
    head->next->next->next->next->next = NULL;

    printf("Original List:\n");
    printData(head);

    operations(head);

    printf("Final List:\n");
    printData(head);

    return 0;
}

void printData(struct Node* pntr) {
    printf("List: ");
    while (pntr != NULL) {
        printf("%d -> ", pntr->data);
        pntr = pntr->next;
    }
    printf("\n"); // Add a newline character for formatting
}


