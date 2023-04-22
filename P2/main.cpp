#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

#define moviesNum 10

class Movie{
public:
    int ll;
    string name;
    float rating;

    Movie(){
        this->ll = -1;
        this->name = "";
        this->rating = -1.0;
    }

    friend ostream& operator<<(ostream &os, const Movie &m){
        return os<<"Lp. "<<m.ll<<"\nName: "<<m.name<<"\nRating: "<<m.rating<<"\n";
    }
};

void bubble_sort(Movie *array){
    for(int i=0; i < moviesNum-1; i++)
        for(int j=i; j < moviesNum - 1 - i; j++){
            if(array[j].rating > array[j+1].rating){
                auto tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
}

void quick_sort(Movie *array, int left, int right){
    if(right <= left)
        return;

    int i = left-1, j = right+1;
    float pivot = array[(left + right) / 2].rating;

    while(true){
        while(pivot < array[++i].rating);
        while(pivot > array[--j].rating);

        if(i <= j){
            auto tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        } else
            break;
    }

    quick_sort(array, left, j);
    quick_sort(array, i, right);
}

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

void mergeSort(Movie *array, int const left, int const right)
{
    if (left >= right)
        return;

    auto mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

void bucketInsertionSort(vector<Movie> &array, int array_size){
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
    vector<vector<Movie>> tmp;

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

bool isSorted(Movie *array, int array_length){
    for(int i = 1; i < array_length; i++)
        if(array[i - 1].rating > array[i].rating)
            return false;
    return true;
}

int main(){
    ifstream file("../projekt2_dane.csv", ios::in);
    string tmp; getline(file, tmp);

    Movie movies[moviesNum];

    if(file.good()){
        for(auto &movie : movies){
            getline(file, tmp);

            short firstComma, secondComma;
            firstComma = tmp.find_first_of(',');
            secondComma = tmp.find_last_of(',');

            movie.ll = stoi(tmp.substr(0, firstComma));
            movie.name = tmp.substr(firstComma+1, tmp.size() - firstComma - (tmp.size() - secondComma) - 1);
            movie.rating = stof(tmp.substr(secondComma+1, tmp.size()-secondComma));
        }

        file.close();
    }
    else {
        cout<<"ERROR\n";
    }

    auto t1 = high_resolution_clock::now();
//    bubble_sort(movies);
//    quick_sort(movies, 0, moviesNum);
//    mergeSort(movies, 0, moviesNum - 1);
    bucketSort(movies, 4, moviesNum);
    auto t2 = high_resolution_clock::now();

//    for(const Movie &m: movies){
//        cout<<m<<"\n";
//    }

    duration<double, milli> func_time_milli = t2 - t1;
    cout<<"Func time(s): "<<func_time_milli.count() / 1000<<"\n";
    cout<<"Func time(ms): "<<func_time_milli.count()<<"\n";
    cout<<"Array is sorted? "<<isSorted(movies, moviesNum)<<endl;

    return 0;
}
