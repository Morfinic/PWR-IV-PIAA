#include "Node.h"

class LinkedList {
private:
    Node* head;
public:
    explicit LinkedList(int data);
    void insert(int val);
    void purge();
    void delete_node(int offset);
    void print();
};
