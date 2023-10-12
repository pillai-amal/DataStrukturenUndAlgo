#include <stdio.h>
#include <stdlib.h>

//Data structure
//----------------------------------------------------------------
struct Bintree {
    int data;
    struct Bintree* left;
    struct Bintree* right;
};
//----------------------------------------------------------------

//Function Declarations
//----------------------------------------------------------------
struct Bintree* insert(struct Bintree* root, int data);
void search(struct Bintree* root, int data);
void printTree(struct Bintree* root);
void freeTree(struct Bintree* root);
void displayMenu();
//----------------------------------------------------------------

//Main Function
//----------------------------------------------------------------
int main() {

    struct Bintree* root = NULL;
    displayMenu();
    return 0;
}
//----------------------------------------------------------------

//Function Definitions
//----------------------------------------------------------------
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
    if(root->data == s_data) {
        printf("%d is found in the tree", s_data);
    } else if(root->data > s_data) { 
        search(root->right, s_data);
    } else {
        search(root->left, s_data);
    }
    printf("%d is NOT found in the tree", s_data);
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

void displayMenu() {
    do {
        int choice, data;
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    root = insert(root, data);
                    printf("Do you want to insert more elements? (1 for Yes, 0 for No): ");
                    scanf("%d", &choice);
                } while (choice == 1);
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
}
