#include <stdio.h>

void insertion_sort(int array[], int size){
    for(int i = 1; i < size; i++){
        int j;
        int key = array[i];
        for (j =  i - 1; j >= 0 && key < array[j]; j--){
            array[j+1] = array[j];
        }
        array[j + 1] = key;
    }
}
int main(){
    int array[] = {1, 5, 6, 8, 2, 9};
    int size = sizeof(array) / sizeof(array[0]);

    insertion_sort(array, size);

    for (int i = 0; i < size; i++){
        printf("%i ", array[i]);
    }
}