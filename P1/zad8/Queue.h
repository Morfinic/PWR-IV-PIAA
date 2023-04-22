#include "Node.h"

class Queue{
private:
    Node* head{};
public:
    explicit Queue(int data);
    void push(int val);
    void purge();
    int pop();
    void print();
};
