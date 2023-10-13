#include <stdio.h>
#include <stdlib.h>

// Data structure
struct Bintree {
    int data;
    struct Bintree* left;
    struct Bintree* right;
};

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Deque {
    Node* front;
    Node* back;
} Deque;

// Function Declarations
struct Bintree* insert(struct Bintree* root, int data);
void search(struct Bintree* root, int s_data);
void printTree(struct Bintree* root);
void freeTree(struct Bintree* root);
void displayMenu(struct Bintree** root, Deque* deque);
void insertFront(Deque* deque, int data);
void insertIntoDequeInInterval(struct Bintree* root, Deque* deque, int a, int b);
void printDeque(Deque* deque);

// Main Function
int main() {
    struct Bintree* root = NULL;
    Deque deque; // Create a deque
    deque.front = NULL;
    deque.back = NULL;
    displayMenu(&root, &deque);
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

void insertFront(Deque* deque, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }
    newNode->data = data;
    newNode->next = deque->front;
    deque->front = newNode;
    if (deque->back == NULL) {
        deque->back = newNode;
    }
}

void insertIntoDequeInInterval(struct Bintree* root, Deque* deque, int a, int b) {
    if (root == NULL) {
        return;
    }

    if (root->data >= a && root->data <= b) {
        insertFront(deque, root->data);
    }

    insertIntoDequeInInterval(root->left, deque, a, b);
    insertIntoDequeInInterval(root->right, deque, a, b);
}

void printDeque(Deque* deque) {
    Node* current = deque->front;
    printf("Deque elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void displayMenu(struct Bintree** root, Deque* deque) {
    int choice, data, searchValue, upperBound;
    int a, b; // Declare 'a' and 'b' here

    do {
        printf("\nASSIGNMENT II - TREE\n");
        printf("\n1. Insert data\n");
        printf("2. Print Tree (Inorder Traversal)\n");
        printf("3. Search for value\n");
        printf("4. Free Tree\n");
        printf("5. Insert numbers in interval [a, b] into Deque\n");
        printf("6. Insert numbers in interval [0, b] into Deque\n");
        printf("7. Print Deque\n");
        printf("8. Exit\n");
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
                printf("Enter the interval [a, b] to insert into the deque from the binary tree:\n");
                printf("a: ");
                scanf("%d", &a);
                printf("b: ");
                scanf("%d", &b);
                insertIntoDequeInInterval(*root, deque, a, b);
                printf("Numbers within the interval [%d, %d] inserted into the deque.\n", a, b);
                break;
            case 6:
                printf("Enter the upper bound (b) to insert into the deque from the binary tree: ");
                scanf("%d", &upperBound);
                insertIntoDequeInInterval(*root, deque, 0, upperBound);  // Lower bound is always 0
                printf("Numbers within the interval [0, %d] inserted into the deque.\n", upperBound);
                break;
            case 7:
                printDeque(deque);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);
}
