#include "Dequeue.h"

Dequeue::Dequeue() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool Dequeue::isEmpty() {
    if(head == nullptr && tail == nullptr)
        return true;
    return false;
}

int Dequeue::getSize() {
    return size;
}

char Dequeue::first() {
    return head->val;
}

char Dequeue::last() {
    return tail->val;
}

char Dequeue::orphanRemove() {
    char return_val = head->val;
    Node **headPoint = &head, **tailPoint = &tail, *tmpHead = head;
    delete tmpHead;
    *headPoint = nullptr;
    *tailPoint = nullptr;
    size--;
    return return_val;
}

void Dequeue::insertFirst(char data) {
    if(head == nullptr && tail == nullptr){
        Node *new_node = new Node(data);
        head = new_node;
        tail = new_node;
        size++;
        return;
    }
    Node *newHead = new Node(data), **tmp = &head;
    newHead->next = head;
    head->prev = newHead;
    *tmp = newHead;

    size++;
}

char Dequeue::shift() {
    if(size == 1){
        return orphanRemove();
    }

    Node **tmp = &head, *newHead = head->next, *currHead = head;
    char return_val = head->val;

    newHead->prev = nullptr;
    *tmp = newHead;
    delete currHead;

    size--;

    return return_val;
}

void Dequeue::insertLast(char data) {
    if(head == nullptr && tail == nullptr){
        Node *new_node = new Node(data);
        head = new_node;
        tail = new_node;
        size++;
        return;
    }
    Node *newTail = new Node(data), **tmp = &tail;
    newTail->prev = tail;
    tail->next = newTail;
    *tmp = newTail;

    size++;
}

char Dequeue::pop() {
    if(size == 1){
        return orphanRemove();
    }

    Node **tmp = &tail, *newTail = tail->prev, *currTail = tail;
    char return_val = tail->val;

    newTail->next = nullptr;
    *tmp = newTail;
    delete currTail;

    size--;

    return return_val;
}

bool Dequeue::isPal() {
    while(size > 1) {
        char c1 = this->shift(), c2 = this->pop();
        if(c1 != c2)
            return false;
    }
    if(!this->isEmpty())
        this->pop();
    return true;
}
