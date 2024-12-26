#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int array[], int low, int high){
    if (low >= high){
        return ;
    }

    int mid = low + (high - low) / 2;
    int pivot = array[mid];

    swap(&array[mid], &array[high]); // Moving the middle pivot to end 

    //Change this loop to i is low and j is high    
    // int i = low;
    // for(int j = low; j < high; j++){
    //     if (array[j] < pivot) {
    //         swap(&array[i], &array[j]);
    //         i++;
    //     }
    // }
    // swap(&array[i], &array[high]);

    int i = low;
    for(int j = high; i < j;){
        if (array[i] > pivot && array[j] < pivot){
            swap(&array[i++], &array[j--]);
        } else if(array[i] <= pivot){
            i++;
        } else {
            j--;
        }
    }
    swap(&array[i], &array[high]);

    quick_sort(array, low, i - 1);
    quick_sort(array, i + 1, high);

}
int main(){
    int array[] = {9, 3, 5, 6, 8, 2, 9};
    int size = sizeof(array) / sizeof(array[0]);

    quick_sort(array, 0, size - 1);

    for (int i = 0; i < size; i++){
        printf("%i ", array[i]);
    }
}