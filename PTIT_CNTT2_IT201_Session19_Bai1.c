#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode( int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

void printTree(Node* root) {
    if (root == NULL) {
        printf("Khong co phan tu nao trong tree \n");
        return;
    }
    Node* current = root;
    while (current != NULL) {
        printf("data : %d ,left : %d ,right : %d", current->data,current->left,current->right);
        current = current->left;
    }
}


int main(){
    Node* root = NULL;
    root = createNode(2);
    root->left = createNode(3);
    root->left->left = createNode(5)
    root->right = createNode(3);
    return 0;
}