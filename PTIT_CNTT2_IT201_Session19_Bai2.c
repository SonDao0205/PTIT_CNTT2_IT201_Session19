#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("khong the cap phat \n");
        return;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
}
void preoder(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preoder(root->left);
    preoder(root->right);
}
int main() {
    Node* root = NULL;
    root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    preoder(root);
}