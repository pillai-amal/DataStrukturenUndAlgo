#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertX(struct Node *pntr, int x) {
    if (pntr == NULL) {
        printf("nothing to insert, empty list");
        return;
    }
    while (pntr != NULL) {
        if (pntr->data < 0) {
            struct Node *xLoc = (struct Node *)malloc(sizeof(struct Node));
            xLoc->data = x;
            xLoc->next = pntr->next;
            pntr->next = xLoc;
            pntr = xLoc->next;
        } else {
            pntr = pntr->next;
        }
    }
}

void printData(struct Node *pntr) {
    while (pntr != NULL) {
        printf("%d ->", pntr->data);
        pntr = pntr->next;
    }
}

void insertMenu(struct Node *head) {
    int x;
    printf("Enter the value to insert: ");
    scanf("%d", &x);
    insertX(head, x);
}

void printMenu(struct Node *head) {
    printf("Linked List: ");
    printData(head);
    printf("\n");
}

void printInitialList(struct Node *head) {
    printf("Initial List: ");
    printData(head);
    printf("\n");
}

int main() {
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 3;
    head->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->data = 5;
    head->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->data = 7;
    head->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->next->data = -8;
    head->next->next->next->next = (struct Node *)malloc(sizeof(struct Node));
    head->next->next->next->next->data = 34;
    head->next->next->next->next->next = NULL;

    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Show the initial list\n");
        printf("2. Insert a value after nodes with negative data\n");
        printf("3. Print the linked list after the insertion process\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printInitialList(head);
                break;
            case 2:
                insertMenu(head);
                break;
            case 3:
                printMenu(head);
                break;
            case 4:
                // Free memory and exit
                while (head != NULL) {
                    struct Node *temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}