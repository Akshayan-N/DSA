#include <stdio.h>

void heapify(int array[], int N, int i){
    int largest = i;
    int left_child_index = 2 * i + 1;
    int right_child_index= 2 * i + 2;

    if (left_child_index < N && array[left_child_index] > array[largest]){
        largest = left_child_index;
    }
    if (right_child_index < N && array[right_child_index] > array[largest]){
        largest = right_child_index;
    }
    if (largest != i){
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;

        heapify(array, N, largest);
    }
}
void heap_sort(int array[], int size){
    //Heapify ( Max heap)
    for(int i = size / 2; i >= 0; i--){
        heapify(array, size, i);
    }

    //delete all the elements
    for(int i = size - 1; i >= 0; i--){
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;

        heapify(array, i, 0);
    }
}
int main(){
    int array[] = {1, 5, 6, 8, 2, 9};
    int size = sizeof(array) / sizeof(array[0]);

    heap_sort(array, size);

    for (int i = 0; i < size; i++){
        printf("%i ", array[i]);
    }
}

