#include <stdlib.h>
#include <stdio.h> 

#include "tree_struct.c"
#include "tree_stack.c"
#include "tree_queue.c"

void InOrderTraversal(Node* root) {
    
    if (root == NULL) return ;

    InOrderTraversal(root->left);
    printf("%i ", root->value);
    InOrderTraversal(root->right);

    return ;
}

void preOrderTraversal(Node* root) {
    
    if (root == NULL) return ;

    printf("%i ", root->value);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

    return ;
}

void postOrderTraversal(Node* root) {
    
    if (root == NULL) return ;  

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%i ", root->value);

    return ;
}

void breadthFirstSearch(Node* root) {
    queueNode* head = createQueueNode(root);
    
    while(head != NULL) {
        Node* currentNode = dequeue(&head);
        printf("%i ", currentNode->value);
        enqueue(&head, currentNode->left);
        enqueue(&head, currentNode->right);
    }
    return ;
}

void depthFirstSearch(Node* root) {
    stackNode* head = createStackNode(root);  
    while(head != NULL) {
        Node* currentNode = popStack(&head);
        printf("%i ", currentNode->value);
        pushStack(&head, currentNode->right);
        pushStack(&head, currentNode->left);
    }
    return ;
}