#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printData(struct Node* pntr) {
    while (pntr != NULL) {
        printf("%d -> ", pntr->data);
        pntr = pntr->next;
    }
    printf("NULL\n");
}

void removeLargest(struct Node** head) {
    if (*head == NULL) {
        printf("Empty List, Nothing to do!\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* biggest = *head;
    struct Node* prevBiggest = NULL;

    while (current != NULL) {
        if (current->data > biggest->data) {
            biggest = current;
            prevBiggest = prev;
        }
        prev = current;
        current = current->next;
    }

    if (prevBiggest != NULL) {
        prevBiggest->next = biggest->next;
    } else {
        *head = biggest->next;
    }

    printf("List after removing largest: ");
    printData(*head);

    free(biggest);
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

    printf("Original List: ");
    printData(head);

    removeLargest(&head);

    // Free the memory used by the remaining nodes
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
