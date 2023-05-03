#include "mergeSort.h"

void merge(Movie *array, int const left, int const mid, int const right){
    int const left_arr_size = mid - left + 1;
    int const right_arr_size = right - mid;

    auto left_arr{new Movie[left_arr_size]}, right_arr{new Movie[right_arr_size]};

    for(int i = 0; i < left_arr_size; i++)
        left_arr[i] = array[left + i];
    for(int j = 0; j < right_arr_size; j++)
        right_arr[j] = array[mid + 1 + j];

    int idx_arr_one{0}, idx_arr_two{0}, idx_merged_arr{left};

    while(idx_arr_one < left_arr_size && idx_arr_two < right_arr_size){
        if(left_arr[idx_arr_one].rating <= right_arr[idx_arr_two].rating){
            array[idx_merged_arr] = left_arr[idx_arr_one];
            idx_arr_one++;
        } else{
            array[idx_merged_arr] = right_arr[idx_arr_two];
            idx_arr_two++;
        }
        idx_merged_arr++;
    }

    while(idx_arr_one < left_arr_size){
        array[idx_merged_arr] = left_arr[idx_arr_one];
        idx_arr_one++;
        idx_merged_arr++;
    }
    while(idx_arr_two < right_arr_size){
        array[idx_merged_arr] = right_arr[idx_arr_two];
        idx_arr_two++;
        idx_merged_arr++;
    }

    delete[] left_arr;
    delete[] right_arr;
}

void mergeSort(Movie *array, int const left, int const right){
    if (left >= right)
        return;

    auto mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}
