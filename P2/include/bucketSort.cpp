#include "bucketSort.h"

void bucketInsertionSort(std::vector<Movie> &array, int array_size){
    int j; Movie key;
    for (int i = 1; i < array_size; i++){
        key = array[i];
        j = i - 1;

        while(array[j].rating > key.rating){
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void bucketSort(Movie *array, int num_buckets, int array_size){
    float maxEl{array[0].rating}, minEl{array[0].rating};
    for(int i = 1; i < array_size; i++){
        if(array[i].rating > maxEl)
            maxEl = array[i].rating;
        if(array[i].rating < minEl)
            minEl = array[i].rating;
    }
    auto range = (maxEl - minEl) / num_buckets;
    std::vector<std::vector<Movie>> tmp;

    for(int i = 0; i < num_buckets; i++)
        tmp.emplace_back();

    for(int i = 0; i < array_size; i++){
        int idx = int((array[i].rating - minEl) / range);
        if(idx == num_buckets)
            tmp[idx-1].push_back(array[i]);
        else
            tmp[idx].push_back(array[i]);
    }

    for(auto &bucket: tmp) {
        if(!bucket.empty())
            bucketInsertionSort(bucket, bucket.size());
    }

    int k{0};
    for(auto bucket: tmp)
        if(!bucket.empty())
            for(auto movie: bucket){
                array[k] = movie;
                k++;
            }
}