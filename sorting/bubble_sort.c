#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int* array, int size) {
  int swap_flag;
  for (int start = 0; start < size; start++) {
    swap_flag = false; // zero can be used instead
    for (int inner_start = start + 1; inner_start < size; inner_start++) {
      if (array[start] > array[inner_start]) {

        //---[Swapping using pointer]--//
        swap(&array[start], &array[inner_start]);
        swap_flag = true;

        //---[Note]---//
        // if you dont understand the swap using pointers
        // you can implement as you need 
        // dont break your head about it :)
      }
    }
    
    //If no swap is occured break the loop
    //because array will be sorted
    if (swap_flag == false){
      break;
    }
  }
}

int main(int argc, char* argv[]) {
  
  if (argc < 2) {
    printf("Usage : %s <array>\n", argv[0]);
    return 1;
  }

  int array_size = argc - 1;
  int array[array_size];

  printf("Array Before Sorting: ");
  for (int index = 0; index < array_size; index++) {  
    array[index] = atoi(argv[index+1]);
    printf("%i ", array[index]);
  }
  printf("\n");

  bubble_sort(array, array_size);

  printf("Array After sorting : ");
  for (int index = 0; index < array_size; index++) {
    printf("%i ", array[index]);
  }
  printf("\n");
}

