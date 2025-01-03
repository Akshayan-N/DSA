#include <stdio.h>

//---[Importing Tree Struct]---//
// #include "./linked_list/tree_struct.c"
#include "./linked_list/binary_tree_operations.c"

void insert_value(Node** root, int data) {
    if (*root == NULL) {
        (*root) = createNode(data);
        return ;
    }

    Node* temp = (*root);
    if (temp->value < data){
        if (temp->right == NULL){
            temp->right = createNode(data);
        } else {
            insert_value(&temp->right, data);
        }
    } else {
        if (temp->left == NULL){
            temp->left = createNode(data);
        } else {
            insert_value(&temp->left, data);
        }
    }
}

Node* binarySearch(Node* root, int target) {
    if (root == NULL) return NULL;

    if (root->value == target) {
        return root;
    } else if (root->value < target){
        return binarySearch(root->right, target);
    } else {
        return binarySearch(root->left, target);
    }
}

Node* getSuccessor(Node* root) {
    root = root->right;

    while(root != NULL && root->left != NULL) {
        root = root->left;
    }

    return root;
}

Node* delete_value(Node** root_pointer, int target) {
    
    Node* root = (*root_pointer);
    if (root == NULL) return NULL;

    if (root->value == target) {
        
        Node* temp;
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } 

        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        } 

        temp = getSuccessor(root);
        root->value = temp->value;

        root->right = delete_value(&root->right, temp->value);

    } else if (root->value < target){
        root->right = delete_value(&root->right, target);
        
    } else {
        root->left = delete_value(&root->left, target);
    }
    return root;
}

int main(int argc, char* argv[]) {
    //---[checking for proper arguments]---//
    if (argc < 2) {
        printf("Usage: %s <elements>\n", argv[0]);
        return 1; 
    }

    //---[Storing the arguments in Array]---//
    int array_size = argc - 1;
    int array[array_size];
    for (int index = 1; index <= array_size; index++) {
        array[index-1] = atoi(argv[index]);
    }

    Node* root = NULL;

    for (int index = 0; index < array_size; index++){
        insert_value(&root, array[index]);
    }

    //---[All binary tree operation can be performed]---//
    printf("BFS : ");
    breadthFirstSearch(root);
    printf("\n");

    //---[Binary Searchin]---//
    int target;
    printf("Enter the element to : ");
    scanf("%i", &target);
    
    Node* target_pointer = binarySearch(root, target);
    if (target_pointer != NULL) {
        printf("%i is present in Binary Tree\n", target);
    } else {
        printf("%i is not present in Binary Tree\n", target);
    }

    //---[Deletion]---//
    printf("Enter the element to Delete: ");
    scanf("%i", &target);
    
    delete_value(&root, target);
    
    target_pointer = binarySearch(root, target);
    if (target_pointer != NULL) {
        printf("%i is present in Binary Tree\n", target);
    } else {
        printf("%i is not present in Binary Tree\n", target);
    }
}
