#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1) return NULL;

    struct Node* newNode = createNode(data);
    printf("Enter left child of %d:\n", data);
    newNode->left = insertNode();

    printf("Enter right child of %d:\n", data);
    newNode->right = insertNode();

    return newNode;
}

void inorderTraversal(struct Node* node) {
    if (node == NULL) return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

void preorderTraversal(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void postorderTraversal(struct Node* node) {
    if (node == NULL) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    printf("%d ", node->data);
}

int main() {
    struct Node* root = NULL;
    printf("Create the binary tree:\n");
    root = insertNode();

    int choice;
    printf("Enter 1 for Inorder, 2 for Preorder, 3 for Postorder: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Inorder Traversal: ");
            inorderTraversal(root);
            break;
        case 2:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            break;
        case 3:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}
