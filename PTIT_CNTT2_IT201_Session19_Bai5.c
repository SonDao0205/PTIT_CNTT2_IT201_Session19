#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("khong the cap phat bo nho \n");
        return ;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int inorder(Node* root,int value) {
    if(root == NULL) {
        return;
    }
    int flag = 0;
    inorder(root->left,value);
    if(root->data == value) {
        flag = 1;
        return 0;
    }
    inorder(root->right,value);
    if (!flag) {
        return -1;
    }
}
int main() {
    Node* root = NULL;
    root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int result = inorder(root->left,3);
    if(result == -1) {
        printf("False \n");
    }else {
        printf("True \n");
    }
}