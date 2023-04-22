#include <iostream>
#include <fstream>
using namespace std;

// Zad.1_2
void fill_array(int* array, int x, int n, int m){
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            array[i * n + j] = rand() % x;
}

void print_array(int* array, int n, int m){
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << array[i * n + j] << " ";
        cout << endl;
    }
}

int find_max(int* array, int n, int m){
    int max = -1;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if(max < array[i * n + j])
                max = array[i * n + j];
    }

    return max;
}

void save_to_file(int* array, int n, int m){
    ofstream file("../txt_files/zapis.txt", ios::out);

    if(file.is_open()){
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                file << array[i * n + j] << " ";
            file << "\n";
        }
        file.close();
    }
    else
        cout<<"Error opening a file\n";
}

void read_from_file(int* array, int n , int m){
    ifstream file("../txt_files/zapis.txt", ios::in);

    if(file.is_open()){
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
                int tmp;
                file >> tmp;
                array[i * n + j] = tmp;
            }
        }
        file.close();
    }
    else
        cout<<"Error opening a file\n";
}

void save_to_bin_file(int* array, int n, int m){
    ofstream file("../txt_files/zapis_bin.txt", ios::binary);

    file.write(reinterpret_cast<char*>(array), sizeof(int) * m * n);

    file.close();
}

void read_from_bin_file(int* array, int n, int m){
    ifstream file("../txt_files/zapis_bin.txt", ios::binary);

    file.read(reinterpret_cast<char*>(array), sizeof(int) * m * n);

    file.close();
}

int main(){
    // Zad.1_2
    int* array2d;
    int w = 1;

    while(w)
    {
        cout<<"\n1. Stworz tablice\n2. Wczytaj tablice z pliku\n3. Zapisz tablice w pliku\n"
              "4. Wczytaj tablice z pliku binarnego\n5. Zapisz tablice w pliku binarnym\n"
              "6. Wypelnienie tablicy\n7. Wyswietlenie tablicy\n8. Znajdz max w tablicy\n"
              "Opcja:";
        cin>>w;

        switch (w) {
            case 0:
                break;
            case 1:
                int n, m;
                cout << "Podaj wymiary macierzy (a x b): \n";
                cin >> n >> m;
                array2d = new int[n * m];
                break;
            case 2:
                read_from_file(array2d, n, m);
                break;
            case 3:
                save_to_file(array2d, n, m);
                break;
            case 4:
                read_from_bin_file(array2d, n, m);
                break;
            case 5:
                save_to_bin_file(array2d, n, m);
                break;
            case 6:
                fill_array(array2d, 10, n, m);
                break;
            case 7:
                print_array(array2d, n, m);
                break;
            case 8:
                cout << "Max: " << find_max(array2d, n, m) << endl;
                break;
        }
    }

    delete[] array2d;

    return 0;
}