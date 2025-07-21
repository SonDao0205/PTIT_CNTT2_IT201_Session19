#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;
typedef struct Queue {
   Node* item[MAX];
    int front;
    int rear;
}Queue;
void init(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("khong the cap phat bo nho \n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* enqueue(Queue* q,Node* value) {
    if (q->rear < MAX) {
        q->item[q->rear++] = value;
    }else {
        printf("Queue day \n");
    }
}
Node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue rong \n");
        return NULL;
    }
   return q->item[q->front++];
}
int levelorder(Node* root,int value) {
    if (root == NULL) return;
    Queue q;
    init(&q);
    enqueue(&q, root);
    int flag = 0;
    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        if (current->data == value) {
            printf("%d ", current->data);
            flag = 1;
            return 0;
        }
        if (current->left )
            enqueue(&q, current->left);
        if (current->right )
            enqueue(&q, current->right);
    }
    printf("\n");
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
    int result = levelorder(root->left,3);
    if(result == -1) {
        printf("False \n");
    }else {
        printf("True \n");
    }
    return 0;
}