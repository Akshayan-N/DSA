#include <stdlib.h>
//---[Stack Structure and function for DFS]---//
typedef struct stackNode {
    Node* node;
    struct stackNode* next;
} stackNode;

stackNode* createStackNode(Node* data) {
    stackNode* newNode = (stackNode*) malloc(sizeof(stackNode));
    //---[Memory Allocation Check]---//
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->node = data;
    newNode->next = NULL;

    return newNode;
}

void pushStack(stackNode** head, Node* data) {
    if (data == NULL) return ;

    stackNode* newNode = createStackNode(data);
    newNode->next = (*head);
    (*head) = newNode;

    return ;
}

Node* popStack(stackNode** head) {

    if (*head == NULL) {
        printf("Stack Under Flow!!!\n");
        exit(0);
    }

    Node* currentNode = (*head)->node;

    stackNode* temp = *head;
    *head = (*head)->next;

    free(temp);
    return currentNode;
}
