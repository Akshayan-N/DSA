// Array Representation
//
// left child index --> 2 * parent_index + 1
// right child index--> 2 * parent_index + 2
// parent_index --> child index / 2 
//
#include <stdio.h>
#include <stdlib.h>

void preOrderTraversal(int* array, int index, int size) {

  //---[Check out of Range]---//
  if (index >= size) {
    return ;
  }

  printf("%i ", array[index]);
  preOrderTraversal(array, index * 2 + 1, size); // Left  Child Traversal
  preOrderTraversal(array, index * 2 + 2, size); // Right Child Traversal

}
void postOrderTraversal(int* array, int index, int size) {

  //---[Check out of Range]---//
  if (index >= size) {
    return ;
  }
  postOrderTraversal(array, index * 2 + 1, size); // Left  Child Traversal
  postOrderTraversal(array, index * 2 + 2, size); // Right Child Traversal
  printf("%i ", array[index]);

}
void inOrderTraversal(int* array, int index, int size) {

  //---[Check out of Range]---//
  if (index >= size) {
    return ;
  }

  inOrderTraversal(array, index * 2 + 1, size); // Left  Child Traversal
  printf("%i ", array[index]);
  inOrderTraversal(array, index * 2 + 2, size); // Right Child Traversal
}

void breathFirstSearch(int* array,  int size) {
  int queue[size];
  int head = -1;
  int tail = 0;

  queue[0] = 0;
  int index;
  while (head != tail) {
    index = queue[++head];

    printf("%i ", array[index]);
    
    int left_child = index * 2 + 1;
    int right_child = left_child + 1;
    if (left_child < size) {
      queue[++tail] = left_child;
    }
    if (right_child < size) {
      queue[++tail] = right_child;
    }
  }
}

void depthFirstSearch(int* array, int size) {
  int stack[size];
  int stack_pointer = 0;
  stack[stack_pointer] = 0;

  int index;
  while(stack_pointer != -1) {
    index = stack[stack_pointer--];
    printf("%i ", array[index]);

    int left_child = index * 2 + 1;
    int right_child = left_child + 1;
    if (right_child < size) {
      stack[++stack_pointer] = right_child;
    }
    if (left_child < size) {
      stack[++stack_pointer] = left_child;
    }
  }
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

  //---[Pre-Order Traversal]---//
  printf("Pre-Order : ");
  preOrderTraversal(array, 0,  array_size);
  printf("\n");
  
  //---[In-Order Traversal]---//

  printf("Post-Order : ");
  postOrderTraversal(array, 0,  array_size);
  printf("\n");
  
  //---[Post-Order Traversal]---//

  printf("In-Order : ");
  inOrderTraversal(array, 0,  array_size);
  printf("\n");

  //---[BFS]---//
  printf("BFS : ");
  breathFirstSearch(array,  array_size);
  printf("\n");

  //---[DFS]---//
  printf("DFS : ");
  depthFirstSearch(array, array_size);
  printf("\n");
  return 0;
}
