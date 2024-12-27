#include <stdio.h>
#include <stdlib.h>

int binary_search(int* array, int low, int high, int target) {
  //---[Binary Search is for only sorted Array]--//
  //Uses Recursion
  if (low > high) {
    return -1;
  }

  int mid = (low + high) / 2;
  
  int current_value = array[mid];
  if (current_value == target) {
    return mid;
  } else if (current_value > target) {
    return binary_search(array, low, mid-1, target);
  } else  {
    return binary_search(array, mid+1, high, target);
  }
}
int main(int argc, char* argv[]) {

  if (argc < 2) {
    printf("Usage: %s <Array>", argv[0]);
    return 1;
  }

  int array_size = argc - 1;
  int array[array_size];
  for (int index = 1; index <= array_size; index++){
    array[index-1] = atoi(argv[index]); 
  }

  int target;
  printf("Enter the element to search: ");
  scanf("%i", &target);

  int index = binary_search(array, 0, array_size, target);
  if (index == -1) {
    printf("Element not found in the array\n");
  } else {
    printf("Element found in the index %i\n", index);
  }
}
