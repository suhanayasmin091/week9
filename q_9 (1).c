// Program to check whether a given tree is balanced
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int isBalanced(struct Node* root) {
    if (root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diff = leftHeight - rightHeight;
    if (diff < 0) diff = -diff;  

    if (diff > 1)
        return 0; 

    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(6);  

    if (isBalanced(root))
        printf("The tree is balanced.\n");
    else
        printf("The tree is NOT balanced.\n");

    return 0;
}
