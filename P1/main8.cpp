#include <iostream>
#include "zad8/LinkedList.h"
#include "zad8/Queue.h"
using namespace std;

int main(){
    // Lista jednokierunkowa
    LinkedList list(0);
    list.insert(1);
    list.insert(2);
    list.insert(3);

    cout<<"Lista: \n";
    list.print();

    list.delete_node(0);

    cout<<"\nLista after del: \n";
    list.print();

    cout<<"\nList purge: \n";
    list.purge();
    list.print();

    cout<<"Test: \n";
    list.insert(5);
    list.print();

    // Kolejka
    cout<<"\n\nKolejka: \n";
    Queue kolejka(0);
    kolejka.push(1);
    kolejka.push(2);
    kolejka.push(3);
    kolejka.push(4);

    kolejka.print();

    cout<<"\nKolejka pop: \n";
    cout<<"Popped: "<<kolejka.pop()<<"\n";
    kolejka.print();

    cout<<"\nKolejka purge: \n";
    kolejka.purge();
    kolejka.print();

    cout<<"\n\nKolejka: \n";
    kolejka.push(0);
    kolejka.push(20);
    kolejka.push(30);

    kolejka.print();

    cout<<"\nKolejka pop: \n";
    cout<<"Popped: "<<kolejka.pop()<<"\n";
    kolejka.print();

    LinkedList test(0);
    cout<<"\n\n\n";
    test.print();
    test.delete_node(1);
    test.print();

    return 0;
}