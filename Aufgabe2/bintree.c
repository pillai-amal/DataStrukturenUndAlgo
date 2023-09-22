#include<stdlib.h>
#include<stdio.h>

struct node {
    int data;
    int *left;
    int *right;
}
//ein Baum Struktur mit gebenen Data und den zwei Zweigen mit NULL wert wurde erzeugt
struct node* bintreeCreate(int data);

int main() {
    bintreeCreate();
    return 0;
}

struct node* bintreeCreate(int data)() {
    struct node* node = (struct node*)malloc(sizeof( struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}