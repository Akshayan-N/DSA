#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b  = temp;
}

void selection_sort(int array[], int size){
    for (int i = 0; i < size; i++){
        int min_index = i;
        for (int j = i; j < size; j++){
            if (array[min_index] > array[j]){
                min_index = j;
            }
        }
        if (i != min_index){
            //Swapping using reference (or address)
            swap(&array[i], &array[min_index]);

            //if the above is difficult to understand
            // comment and use the below 
            
            //Swapping two elements using values 
            // int temp = array[i];
            // array[i] = array[min_index];
            // array[min_index] = temp;
        }
    }
}

int main(){
    int array[] = {1, 5, 6, 8, 2, 9};
    int size = sizeof(array) / sizeof(array[0]);

    selection_sort(array, size);

    for (int i = 0; i < size; i++){
        printf("%i ", array[i]);
    }
}