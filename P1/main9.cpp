#include <iostream>
#include <string>
#include "zad9/Dequeue.h"
using namespace std;

int main(){
    Dequeue dwuKol;
    string words[] = {"kajak", "test", "12321", "kook"};
    for(auto word: words){
        for(auto c: word){
            dwuKol.insertLast(c);
        }
        cout<<"Slowo: "<<word<<", jest palindromem: "<<dwuKol.isPal()<<"\n";
    }


//    cout<<dwuKol.isEmpty()<<"\n";
//    cout<<dwuKol.getSize()<<"\n";
//    dwuKol.insertFirst('3');
//    dwuKol.insertFirst('2');
//    dwuKol.insertFirst('1');
//    cout<<dwuKol.first()<<"\n";
//    cout<<dwuKol.last()<<"\n";
//    cout<<"---\n"<<dwuKol.shift()<<"\n";
//    cout<<"---\n";
//    cout<<dwuKol.first()<<"\n";
//    cout<<dwuKol.last()<<"\n";
//    cout<<"---\n"<<dwuKol.getSize()<<"\n";
//    dwuKol.insertLast('4');
//    cout<<dwuKol.shift();
//    cout<<"---\n"<<dwuKol.first()<<", "<<dwuKol.last()<<"\n";
//    cout<<"--- Popped: "<<dwuKol.pop()<<"\n"<<dwuKol.first()<<", "<<dwuKol.last()<<"\n";

    return 0;
}