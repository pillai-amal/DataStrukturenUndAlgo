#include<stdio.h>
#include<stdlib.h>

struct Node{
		int data;
		struct Node *next;
};

void insertX(struct Node *pntr, int x){
		if(pntr == NULL){
				printf("nothing to insert, empty list");
				return;
		}
		while(pntr != NULL) {
				if(pntr->data <0){
						struct Node *xLoc = (struct Node*)malloc(sizeof(struct Node));
						xLoc->data = x;
						xLoc->next = pntr->next;
						pntr->next = xLoc;	 
						pntr = xLoc->next;
				} else{
					pntr = pntr->next;
				}
		}

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
		insertX(head, 55);
		printData(head);
		return 0;
}
