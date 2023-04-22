
#include "Node.h"

class Dequeue {
private:
    Node *head;
    Node *tail;
    int size;
    char orphanRemove();
public:
    Dequeue();
    bool isEmpty();
    int getSize();
    char first();
    char last();
    void insertFirst(char data);
    char shift();
    void insertLast(char data);
    char pop();
    bool isPal();
};
