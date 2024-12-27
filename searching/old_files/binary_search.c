#include <stdio.h>

int binary_search(int array[], int low, int high, int target){
    if (low  > high){
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (array[mid] == target){
        return mid;
    } else if (array[mid] < target){
        return binary_search(array, mid+1, high, target);
    } else{
        return binary_search(array, low, mid-1, target);
    }

}

// comment the function when number list is sorted
int compare(int a, int b){
    return a - b;
}

int main(){
    int number_list[] = {1, 5, 6, 8, 2, 9};
    
    int number;
    printf("Enter the number to search : ");
    scanf("%i", &number);

    int size = sizeof(number_list) / sizeof(number_list[0]);
    qsort(number_list, size, sizeof(number_list[0]), compare); // comment when number list is sorted

    int index = binary_search(number_list, 0, size-1, number);

    if (index != -1){
        printf("number %i is present in the index %i", number, index);
    } else {
        printf("Element not found in the list");
    }
}