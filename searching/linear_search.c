#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage : %s <array>\n", argv[0]);
    return 1;
  }
  
  int array_size = argc - 1;
  int array[array_size];
  for(int index = 1; index <= array_size; index++) {
    //--[you can also place you Linear Search here :)]--//
    array[index-1] = atoi(argv[index]);
  }

  int target;
  printf("Enter the element to search : ");
  scanf("%i", &target);

  //---[Linear Search]---//
  for(int index; index < array_size; index++) {
    if (target == array[index]) {
      printf("Target %i found at index %i.\n", target, index);
      return 0;
    }
  }
  printf("Target %i not found in the array\n", target);

  //---[Linear Seach can be placed in funciton]---//
  //As It is simple I kept in the main funciton :)//
}
