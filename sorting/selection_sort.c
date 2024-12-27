#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selection_sort(int* array, int size) {
  for (int i = 0; i < size; i++) {
    int min_index = i;
    int min_value = array[min_index];

    for (int j = i + 1; j < size; j++) {
      if (array[j] < min_value) {
        min_value = array[j];
        min_index = j;
      }
    }

    if (min_index != i) {
      swap(&array[min_index], &array[i]);
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

  selection_sort(array, array_size);

  printf("Array After sorting : ");
  for (int index = 0; index < array_size; index++) {
    printf("%i ", array[index]);
  }
  printf("\n");
}

