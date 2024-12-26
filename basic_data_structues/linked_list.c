// This Implements Linked List as FILO aka LIFO
//
// We can use linked list to implement stack as here
// And also use FIFO and LILO to implement queues
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Node {
   int data;
   struct Node* next;
} Node;

Node* createNode(int data) {
  Node* node = (Node*) malloc(sizeof(Node));
  node->next = NULL;
  node->data = data;
  return node;
} 

void addNode(Node** head, int data) {
  Node* newNode = createNode(data);

  //---[Add the newNode is head]---//
  if (*head != NULL) {
    newNode->next = (*head);
  }

  (*head) = newNode;

}

int removeNode(Node** head) {
  int data = (*head)->data;

  Node* temp = (*head);
  (*head) = (*head)->next;
  
  free(temp);
  return data;
}

void printLinkedlist(Node* head) {
  printf("Linked List : head-> ");
  while (head != NULL) {
    
    printf("%i", head->data);
    head = head->next;
    if (head != NULL) {
      printf(" -> ");
    }
  }
  printf("\n");
}

int main(int argc, char* argv[]){
  if (argc  < 2) {
    printf("Usage: %s <Elements>\n", argv[0]);
    return 1;
  }

  int n = argc - 1;
  
  Node* head = NULL;

  //---[Adding the data from the command line]---//
  for (int index = 1; index <= n; index++){
    addNode(&head, (int) atoi(argv[index]));
  }
  
  //---[Printing the data from linked list]---//
  printLinkedlist(head);
  
  //---[Removing the data from the ]
  while (head != NULL) {
    int data = removeNode(&head);
    printf("[info] Removed %i from linked list\n", data);
  }
}
