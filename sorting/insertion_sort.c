#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertion_sort(int* array, int size) {
  for(int index = 0; index < size; index++){
    int key = array[index];
    int inner_index = index - 1;

    while(inner_index > -1 && array[inner_index] > key) {
      array[inner_index + 1] = array[inner_index];
      inner_index--;
    }
    array[inner_index + 1] = key;
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

  insertion_sort(array, array_size);

  printf("Array After sorting : ");
  for (int index = 0; index < array_size; index++) {
    printf("%i ", array[index]);
  }
  printf("\n");
}

