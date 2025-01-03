#include "binary_tree_operations.c"
int main() {
    //Array to LinkedList
    int array[] = {0, 1, 2, 3, 4 , 5, 6};

    Node* root = NULL;
    root = build_binaryTree(root, array, 0, sizeof(array) / sizeof(array[0]));

    printf("In-Order Traversal : ");
    InOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal : ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal : ");
    postOrderTraversal(root);
    printf("\n");

    printf("BFS: ");
    breadthFirstSearch(root);
    printf("\n");

    printf("DFS: ");
    depthFirstSearch(root);
    printf("\n");
}