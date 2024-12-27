#include <stdio.h>

int linear_search(int array[], int size, int target){
    for (int i = 0; i < size; i++){
        if (target == array[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    int number_list[] = {1, 5, 6, 8, 2, 9};

    int number;
    printf("Enter the number to search : ");
    scanf("%i", &number);

    int size = sizeof(number_list) / sizeof(number_list[0]);

    int index = linear_search(number_list, size, number);
    if (index != -1){
        printf("number %i is present in the index %i", number, index);
    } else {
        printf("Element not found in the list");
    }
}