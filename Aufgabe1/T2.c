#include<stdlib.h>
#include<stdio.h>

struct Node{
		int data;
		struct Node *next;
};


void removeLargest(struct Node *pntr){
		if(pntr == NULL){
				printf("Empty List, Nothing to do!");
				return;
		}
		struct Node *current = pntr;
		struct Node *biggest = pntr;
		struct Node *previous = NULL;
		while(pntr != NULL){
				if(current->data > biggest->data){
						biggest->data = current->data;
						current = biggest; 
				}current = current->next;
		}
		free(biggest);
}

void printData(struct Node *pntr) {
		while(pntr != NULL) {
				printf("%d ->", pntr->data);
				pntr = pntr->next;
		}
}

int main() {
		struct Node *head = (struct Node*)malloc(sizeof(struct Node));		
		head->data = 3;
		head->next = (struct Node*)malloc(sizeof(struct Node));
		head->next->data =5;
		head->next->next = (struct Node*)malloc(sizeof(struct Node));
		head->next->next->data = 7;
		head->next->next->next = (struct Node*)malloc(sizeof(struct Node));
		head->next->next->next->data = -8;
		head->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
		head->next->next->next->next->data = 34;
		head->next->next->next->next->next = NULL;
		removeLargest(head);
		printData(head);
		return 0;
}
