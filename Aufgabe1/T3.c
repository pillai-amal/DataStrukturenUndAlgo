#include<stdlib.h>
#include<stdio.h>

struct Node{
		int data;
		struct Node *next;
};

void insert(struct Node *pntr, int p, int q){
		struct Node *current = pntr;
		while(pntr != NULL){
				current = pntr->next;
		} 
		struct Node *pLoc = (struct Node*)malloc(sizeof(struct Node));
		current->next = pLoc;
		pLoc->data = p;
		struct Node *qLoc = (struct Node*)malloc(sizeof(struct Node));
		pLoc->next = qLoc;
		qLoc->data = q;
		qLoc->next = NULL;	
}

void replaceByZero(struct Node *pntr, int p, int q){
		while(pntr != NULL){
				if(pntr->data/p == q){
						pntr->data = 0;
				}
		}pntr = pntr->next;
}


void operations(struct Node *pntr) {
		insert(pntr,7,4);
		replaceByZero(pntr,7,4);
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
		operations(head);
		printData(head);
		return 0;
}
