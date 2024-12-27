#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int* array, int low, int high) {
  
  int pivot = array[low];

  int i = low;
  int j = high;

  while(i < j) {
    do {
      i++;
    } while(array[i] < pivot)
    do {
      j++;
    }while(array[j] > pivot)

    if (i < j) {
      swap(&array[i], &array[j]);
    }
  }
  return j;
}

void quick_sort(int* array, int low, int high) {
  
  if (low < high) {
    int pi = partition(array, low, high);

    quick_sort(array, low, pi);
    quick_sort(array, pi+1, high);
  }
}
int main(int argc, char* argv[]) {
  
  if (argc < 2) {
    printf("Usage : %s <array>\n", argv[0]);
    return 1;
  }

  int array_size = argc - 1;
  int array[array_size];

  printf("Array Before Sorting: ")
  for (int index = 0; index < array_size; index++) {  
    array[index] = atoi(argv[index+1]);
    printf("%i ", array[index]);
  }
  printf("\n");

  quick_sort(array, array_size);

  printf("Array After sorting : ");
  for (int index = 0; index < array_size; index++) {
    printf("%i ", array[index]);
  }
  printf("\n");
}

