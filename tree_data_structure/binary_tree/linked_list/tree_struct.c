#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right ;
} Node ;

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* build_binaryTree(Node* root, int* array, int index, int size) {
    
    if (index >= size) {
        return NULL;
    }

    root = createNode(array[index]);
    root->left = build_binaryTree(root->left, array, index*2 + 1, size);
    root->right = build_binaryTree(root->right, array, index*2 + 2, size);

    return root;
}
