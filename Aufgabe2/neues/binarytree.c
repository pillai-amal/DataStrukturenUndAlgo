#include <stdio.h>
#include <stdlib.h>

// Data structure
struct Bintree {
    int data;
    struct Bintree* left;
    struct Bintree* right;
};

// Function Declarations
struct Bintree* insert(struct Bintree* root, int data);
void search(struct Bintree* root, int s_data);
void printTree(struct Bintree* root);
void freeTree(struct Bintree* root);
void displayMenu(struct Bintree** root);

// Main Function
int main() {
    struct Bintree* root = NULL;
    displayMenu(&root);
    return 0;
}

// Function Definitions
struct Bintree* insert(struct Bintree* root, int data) {
    if (root == NULL) {
        struct Bintree* newNode = (struct Bintree*)malloc(sizeof(struct Bintree));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void search(struct Bintree* root, int s_data) {
    if (root == NULL) {
        printf("%d is NOT found in the tree\n", s_data);
        return;
    }

    if (root->data == s_data) {
        printf("%d is found in the tree\n", s_data);
    } else if (s_data < root->data) {
        search(root->left, s_data);
    } else {
        search(root->right, s_data);
    }
}

void printTree(struct Bintree* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

void freeTree(struct Bintree* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void displayMenu(struct Bintree** root) {
    int choice, data, searchValue;

    do {
        printf("\nASSIGNMENT II - TREE\n");
        printf("\n1. Insert data\n");
        printf("2. Print Tree (Inorder Traversal)\n");
        printf("3. Search for value\n");
        printf("4. Free Tree\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    *root = insert(*root, data);
                    printf("Do you want to insert more elements? (1 for Yes, 0 for No): ");
                    scanf("%d", &choice);
                } while (choice == 1);
                break;
            case 2:
                printf("Binary Tree (Inorder Traversal):\n");
                printTree(*root);
                printf("\n");
                break;
            case 3:
                printf("Enter the value to search for: ");
                scanf("%d", &searchValue);
                search(*root, searchValue);
                break;
            case 4:
                printf("Freeing the binary tree...\n");
                freeTree(*root);
                *root = NULL;
                printf("Tree freed.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}
