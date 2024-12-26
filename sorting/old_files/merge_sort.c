#include <stdio.h>

void merge_sort(int array[], int low, int high){
    if(low >= high){
        return ;
    }

    int mid = low + (high - low) / 2;

    merge_sort(array, low, mid);
    merge_sort(array, mid+1, high);

    int left_arr_size = mid - low + 1;
    int right_arr_size = high - mid;

    int left_arr[left_arr_size];
    int right_arr[right_arr_size];

    for (int i = 0; i < left_arr_size; i++){
        left_arr[i] = array[low + i];
    }
    for (int i = 0; i < right_arr_size; i++){
        right_arr[i] = array[mid+1+i];
    }

    int i,j,k;
    for(i = 0, j = 0,k = low; i < left_arr_size && j < right_arr_size; k++){
        array[k] = (left_arr[i] <= right_arr[j]) ? left_arr[i++] : right_arr[j++];
    }

    for(; i < left_arr_size; i++){
        array[k++] = left_arr[i];
    }

    for(; j < right_arr_size; j++){
        array[k++] = right_arr[j];
    }
}

int main(){
    int array[] = {1, 3, 5, 6, 6, 8, 2, 9};
    int size = sizeof(array) / sizeof(array[0]);

    merge_sort(array, 0, size - 1);

    for (int i = 0; i < size; i++){
        printf("%i ", array[i]);
    }
}
