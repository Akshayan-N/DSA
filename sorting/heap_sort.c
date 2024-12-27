#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void heapify(int* array, int upper_bound, int size) {
  int largest_index = upper_bound;
  int left_child_index = upper_bound * 2 + 1;
  int right_child_index= upper_bound * 2 + 2;
  
  //---[handling Out of Bound]---//

  if (left_child_index < size && array[largest_index] < array[left_child_index] && left_child_index) {
     largest_index = left_child_index;
   }
   if (right_child_index < size && array[largest_index] < array[right_child_index]) {
     largest_index = right_child_index;
   }

   if (largest_index != upper_bound) {
     swap(&array[largest_index], &array[upper_bound]);
     heapify(array, largest_index, size);
   }

}


void heap_sort(int* array, int size) {
  //--[Coverting Array into Max Heap]--//
  for (int end = size / 2 -1; end > 0; end--) {
    heapify(array, end, size);
  }
  int heap_size= size;
  //--[Delete and Store to sort]---//
  for(int i = size - 1; i > -1; i--) {
    swap(&array[i], &array[0]);
    heapify(array, 0, i);
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

  heap_sort(array, array_size);

  printf("Array After sorting : ");
  for (int index = 0; index < array_size; index++) {
    printf("%i ", array[index]);
  }
  printf("\n");
}

