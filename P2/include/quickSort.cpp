#include "quickSort.h"

void quick_sort(Movie *array, int left, int right){
    if(right <= left)
        return;

    int i = left - 1, j = right + 1;
    float pivot = array[(left + right) / 2].rating;

    while(true){
        while(pivot > array[++i].rating);
        while(pivot < array[--j].rating);

        if(i <= j){
            auto tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        } else
            break;
    }

    if(j > left)
        quick_sort(array, left, j);
    if(i < right)
        quick_sort(array, i, right);
}
