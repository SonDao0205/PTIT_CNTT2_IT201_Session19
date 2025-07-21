#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct SNode {
    Node* data;
    struct SNode *next;
}SNode;
typedef struct Queue {
    SNode* front;
    SNode* rear;
}Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void enqueue(Queue* q, Node* value) {
    SNode* current = (SNode*)malloc(sizeof(SNode));
    current->data = value;
    current->next = NULL;
    if (q->rear == NULL) {
        q->rear = current;
        q->front = current;
        return ;
    }
    q->rear->next = current;
    q->rear = current;
    return ;
}
Node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue rong \n");
        return ;
    }
    SNode* current = q->front;
    Node* temp = current->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(current);
    return temp;
}
int getDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    Node* root = NULL;
    root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int result = getDepth(root);
    printf("Chieu cao cua tree la : %d",result);
    return 0;
}