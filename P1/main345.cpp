#include <iostream>
#include <string>
using namespace std;

int potega(int num, unsigned int n){
    if (n == 1)
        return num;
    return num * potega(num, n - 1);
}

int silnia(int x){
    if(x == 1)
        return 1;
    return x * silnia(x - 1);
}

bool jest_pal(int x, int y, string word){
    if(x >= y)
        return 1;
    if(word[x] != word[y])
        return 0;
    return jest_pal(x + 1, y - 1, word);
}

int cnt = 0;
void permute(string *array, string word, unsigned short l, unsigned short r){
    if(l == r){
        if(jest_pal(0, word.size()-1, word)) {
            array[cnt] = word;
            cnt++;
        }
    }
    for(int i = l; i <= r; i++){
        swap(word[l], word[i]);
        permute(array, word, l+1, r);
        swap(word[l], word[i]);
    }
}

void usunDup(string *array){
    for(int i = 0; i < cnt; i++){
        if(array[i] == "")
            continue;
        string tmp = array[i];
        for(int j = i+1; j < cnt; j++){
            if(i == j)
                break;
            string tmpCompare = array[j];
            if(tmp == tmpCompare)
                array[j] = "";
        }
    }
}

int main(){
    cout<<potega(2, 3)<<endl;
    cout<<silnia(5)<<endl;

    string str[] = {"kajak", "1234321", "PAMSI"};

    for(string words: str)
        cout<<"Slowo: "<<words<<", to palindrom? "<<jest_pal(0, words.size() - 1, words)<<endl;

    cout<<"\nZad.5 permutacja string\n";
    string permuteStr = "kajak";
    int arraySize = silnia(permuteStr.size());
    string strArray[arraySize];
    fill(strArray, strArray+arraySize, "");
    permute(strArray, permuteStr, 0, permuteStr.size()-1);
    cout<<"Permute: \n";
    for(string x: strArray){
        if(x == "")
            continue;
        cout<<x<<endl;
    }
    usunDup(strArray);
    cout<<"\nUsun dup: \n";
    for(string x: strArray){
        if(x == "")
            continue;
        cout<<x<<endl;
    }

    return 0;
}

//5 = 120