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

//bool stringCheck(string *array){
//    for(int i = 0; i < 3; i++)
//        if(array[i].empty())
//            return false;
//    return true;
//}

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

//            if(stringCheck(data)) {
//                array[i].ll = stoi(data[0]);
//                array[i].name = data[1];
//                array[i].rating = stof(data[2]);
//            } else{
//                i--;
//                continue;
//            }

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

int main(){
    int no_data_to_read[] = {10000, 100000, 500000, 1000000, 1010292};

    for(auto num: no_data_to_read){
        auto *movies = new Movie[num];

        get_movies_csv(movies, "projekt2_dane.csv", num);

        auto t1 = high_resolution_clock::now();
        quick_sort(movies, 0, num - 1);
//      mergeSort(movies, 0, num - 1);
//      bucketSort(movies, 3, num);
        auto t2 = high_resolution_clock::now();

//        for(int i = 0; i < num; i++){
//            cout<<movies[i]<<"\n";
//        }

        duration<double, milli> func_time_milli = t2 - t1;
        cout<<"No elems: "<<num<<"\n";
        cout<<"Func time(s): "<<func_time_milli.count() / 1000<<"\n";
        cout<<"Func time(ms): "<<func_time_milli.count()<<"\n";
        cout<<"Is array sorted? "<<isSorted(movies, num)<<"\n\n";

        delete[] movies;
    }

//    ifstream file("../projekt2_dane.csv", ios::in);
//    string tmp; getline(file, tmp);
//
//    Movie movies[moviesNum];

//    if(file.good()){
//        for(auto &movie : movies){
//            getline(file, tmp);
//
//            short firstComma, secondComma;
//            firstComma = tmp.find_first_of(',');
//            secondComma = tmp.find_last_of(',');
//
//            movie.ll = stoi(tmp.substr(0, firstComma));
//            movie.name = tmp.substr(firstComma+1, tmp.size() - firstComma - (tmp.size() - secondComma) - 1);
//            movie.rating = stof(tmp.substr(secondComma+1, tmp.size()-secondComma));
//        }
//
//        file.close();
//    }
//    else {
//        cout<<"ERROR\n";
//    }

//    auto t1 = high_resolution_clock::now();
////    bubble_sort(movies);
////    quick_sort(movies, 0, moviesNum);
////    mergeSort(movies, 0, moviesNum - 1);
//    bucketSort(movies, 3, moviesNum);
//    auto t2 = high_resolution_clock::now();
//
//    for(const Movie &m: movies){
//        cout<<m<<"\n";
//    }
//
//    duration<double, milli> func_time_milli = t2 - t1;
//    cout<<"Func time(s): "<<func_time_milli.count() / 1000<<"\n";
//    cout<<"Func time(ms): "<<func_time_milli.count()<<"\n";
//    cout<<"Is array sorted? "<<isSorted(movies, moviesNum)<<endl;

    return 0;
}
