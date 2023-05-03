#ifndef PWR_IV_PIAA_BUCKETSORT_H
#define PWR_IV_PIAA_BUCKETSORT_H

#include <vector>
#include "Movie.h"

void bucketInsertionSort(std::vector<Movie> &array, int array_size);
void bucketSort(Movie *array, int num_buckets, int array_size);

#endif //PWR_IV_PIAA_BUCKETSORT_H
