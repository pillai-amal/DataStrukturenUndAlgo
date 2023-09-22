#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* bintreeCreate(int data);
struct node* insert(struct node* root, int data);
void printTree(struct node* root);
void freeTree(struct node* root);
void displayMenu();

int main() {
    struct node* root = NULL;
    int choice, data;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Binary Tree (Inorder Traversal):\n");
                printTree(root);
                printf("\n");
                break;
            case 3:
                printf("Freeing the binary tree...\n");
                freeTree(root);
                printf("Exiting program.\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert a node into the binary tree\n");
    printf("2. Print the binary tree\n");
    printf("3. Free the binary tree\n");
    printf("4. Exit\n");
}

struct node* bintreeCreate(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return bintreeCreate(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void printTree(struct node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

void freeTree(struct node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
