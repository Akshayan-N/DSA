#include <stdlib.h>
//---[Queue Structure and function for BFS]---//
typedef struct queueNode {
    Node* node;
    struct queueNode* next;
} queueNode;

queueNode* createQueueNode(Node* data) {
    queueNode* newNode = (queueNode*) malloc(sizeof(queueNode));
    //---[Memory Allocation Check]---//
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->node = data;
    newNode->next = NULL;

    return newNode;
}

void enqueue(queueNode** head, Node* data) {
    if (data == NULL) return ;

    if (*head == NULL) {
        *head = createQueueNode(data);
        return ;
    }
    
    queueNode* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    queueNode* newNode = createQueueNode(data);
    temp->next = newNode;
    newNode = temp;

    return ;
}

Node* dequeue(queueNode** head) {

    if (*head == NULL) {
        printf("queue Under Flow!!!\n");
        exit(0);
    }

    Node* currentNode = (*head)->node;

    queueNode* temp = *head;
    *head = (*head)->next;

    free(temp);
    return currentNode;
}