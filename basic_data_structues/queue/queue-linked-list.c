#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory Allocation Error.\n");
        exit(0);
    }
    newNode->data = value;
    newNode->next = NULL;

    return newNode;

}

void enqueue(Node** head, int data){
    Node* newNode =  createNode(data);

    if (*head == NULL){
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

}

void dequeue(Node** head){
    if (*head == NULL){
        printf("No more elements in the queue.\n");
    } else {
        //Printing the value
        printf("The dequeue value is %i\n", (*head)->data);
        //changing the head and freeing the memory
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
int main(){
    printf("\
MAIN MENU\n \
1. ENQUEUE   \n \
2. DEQUEUE    \n \
3. EXIT   \n");

    Node* queue = NULL;

    while (1){
        int choice;
        printf("Enter your choice : ");
        scanf("%i", &choice);

        switch (choice)
        {
            case 1:
                int value;
                printf("Enter the value to push : ");
                scanf("%i", &value);
                // added new node to the linked list (at end)
                enqueue(&queue, value);
                break;
            case 2:
                // remove the head of linked list
                dequeue(&queue);
                break;
            case 3:
                return 0;
            default:
                printf("Wrong input\n");
            }
    }
}