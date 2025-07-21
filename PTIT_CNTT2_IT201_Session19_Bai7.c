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
void insertLevelOrder(Node* root, int value) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);

        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(&q, current->left);
        }

        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(&q, current->right);
        }
    }
}

void printLevelOrder(Node* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* current = dequeue(&q);
        printf("%d ", current->data);

        if (current->left) enqueue(&q, current->left);
        if (current->right) enqueue(&q, current->right);
    }
}
int main() {
    Node* root = NULL;
    root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    insertLevelOrder(root, 6);

    printf("Cay nhi phan theo level sau khi them:\n");
    printLevelOrder(root);

}