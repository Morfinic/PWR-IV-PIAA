#include <iostream>
#include <fstream>
#include <chrono>
#include "include/quickSort.h"
#include "include/mergeSort.h"
#include "include/bucketSort.h"
using namespace std;
using namespace std::chrono;

ostream& operator<<(ostream &os, const Movie &m){
    os << "Lp. " << m.ll << ", Name: " << m.name << ", Rating: " << m.rating<<"\n";
    return os;
}

//void bubble_sort(Movie *array){
//    for(int i=0; i < moviesNum-1; i++)
//        for(int j=i; j < moviesNum - 1 - i; j++){
//            if(array[j].rating > array[j+1].rating){
//                auto tmp = array[j];
//                array[j] = array[j+1];
//                array[j+1] = tmp;
//            }
//        }
//}

string isSorted(Movie *array, int array_length){
    for(int i = 1; i < array_length; i++)
        if(array[i - 1].rating > array[i].rating)
            return "false";
    return "true";
}

void get_movies_csv(Movie *array, const string &file, int size){
    ifstream file_stream("../" + file, ios::in);
    string tmp; getline(file_stream, tmp);

    if(file_stream.good()){
        for(int i = 0; i < size; i++){
            getline(file_stream, tmp);

            short firstComma, secondComma;
            firstComma = tmp.find_first_of(',');
            secondComma = tmp.find_last_of(',');

            string data[] = {
                    tmp.substr(0, firstComma),
                    tmp.substr(firstComma+1, tmp.size() - firstComma - (tmp.size() - secondComma) - 1),
                    tmp.substr(secondComma+1, tmp.size()-secondComma)
            };

            array[i].ll = stoi(data[0]);
            if(data[1].empty())
                array[i].name = "";
            else array[i].name = data[1];
            if(data[2].empty())
                array[i].rating = -1;
            else array[i].rating = stof(data[2]);
        }

        file_stream.close();
        return;
    }
    else {
        cout<<"ERROR\n";
        return;
    }
}

int last_viable_idx(Movie *array, int last){
    for(int i = last; i >= 0; i--)
        if(!array[i].name.empty() && array[i].rating != -1)
            return i;
    return last;
}

int array_filter(Movie *array, int limit){
    int lastIdx{last_viable_idx(array, limit-1)};

    for(int i = 0; i <= lastIdx; i++){
        if(array[i].name.empty() || array[i].rating == -1){
            swap(array[i], array[lastIdx]);
            lastIdx = last_viable_idx(array, lastIdx-1);
        }
    }

    return lastIdx;
}

void save_result_to_file(Movie *array, int num){
    ofstream file{"../Data/" + to_string(num) + ".txt", ios::out};
    for(int i = 0; i < num; i++){
        file << array[i];
    }
}

float get_average(Movie *array, int array_length){
    float sum{0}, cnt{0};
    for(int i = 0; i < array_length; i++){
        sum += array[i].rating;
        cnt++;
    }
    return sum / cnt;
}

float get_median(Movie *array, int array_length){
    if(array_length % 2 == 0)
        return (array[int(array_length/2)-1].rating + array[int(array_length/2)].rating)/2;
    else return array[int(array_length/2)].rating;
}

int main(){
    int no_data_to_read[] = {10000, 100000, 500000, 1000000, 1010292};
//    int no_data_to_read[] = {10};

    for(auto num: no_data_to_read){
        auto *movies = new Movie[num];
        get_movies_csv(movies, "projekt2_dane.csv", num);

        auto t1 = high_resolution_clock::now();
        int limit{array_filter(movies, num)};
        auto t2 = high_resolution_clock::now();

        cout<<"\nNo elems: "<<limit+1<<"\n";
        duration<double, milli> filter_time_milli = t2 - t1;
        cout<<"Filter time(ms): "<<filter_time_milli.count()<<"\n";

        t1 = high_resolution_clock::now();
            quick_sort(movies, 0, limit);
//            mergeSort(movies, 0, limit);
//            bucketSort(movies, 10, limit+1);
        t2 = high_resolution_clock::now();

//        for(int i = 0; i < num; i++){
//            cout<<movies[i];
//        }

        duration<double, milli> func_time_milli = t2 - t1;
        cout<<"Func time(ms): "<<func_time_milli.count()<<"\n";
        cout<<"Is array sorted? "<<isSorted(movies, limit+1)<<"\n";
        cout<<"Average rating: "<<get_average(movies, limit+1)<<"\n";
        cout<<"Median rating: "<<get_median(movies, limit+1)<<"\n";

        save_result_to_file(movies, num);

        delete[] movies;
    }

    return 0;
}
