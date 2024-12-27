#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//void swap(int* a, int* b) {
//  int temp = *a;
//  *a = *b;
//  *b = temp;
//}

void merge_sort(int* array, int low, int high) {
  //code here to sort
  if (low >= high) {
    return ;
  }

  int mid = (low + high) / 2;
  
  merge_sort(array, low, mid);
  merge_sort(array, mid+1, high);

  //merge
  int left_size = mid - low + 1;
  int left_side[left_size];
  int right_size = high - mid;
  int right_side[right_size];
  
  for (int i = 0; i < left_size; i++) {
    left_side[i] = array[i+low];
  }
  for (int i = 0; i < right_size; i++) {
    right_side[i] = array[mid+1 + i];
  }

  int i,j,k;
  i = j = 0;
  k = low;
  while(i < left_size && j < right_size)  {
    array[k++] = left_side[i] < right_side[j] ? left_side[i++] : right_side[j++] ; 
  }

  while(i < left_size) {
    array[k++] = left_side[i++];
  }
  
  while(j < right_size) {
    array[k++] = right_side[j++];
  }

  return ;
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

  merge_sort(array, 0 , array_size);

  printf("Array After sorting : ");
  for (int index = 0; index < array_size; index++) {
    printf("%i ", array[index]);
  }
  printf("\n");
}

