#include <stdio.h>

void bubble_sort(int array[], int size){
    for (int i = 0; i < size - 1; i++){
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++){
            if (array[j] > array[j + 1]){
                swapped = 1;
                // swappig two values 
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        if (swapped == 0){
            break;
        }
    }
}

int main(){
    int array[] = {1, 5, 6, 8, 2, 9};
    int size = sizeof(array) / sizeof(array[0]);

    bubble_sort(array, size);

    for (int i = 0; i < size; i++){
        printf("%i ", array[i]);
    }
}