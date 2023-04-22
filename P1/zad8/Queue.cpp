#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(int data){
    head = new Node(data);
}

void Queue::push(int val){
    auto* new_node = new Node(val);

    if(head == nullptr){
        head = new_node;
        return;
    }

    Node* tmp = head;
    while(tmp->next != nullptr)
        tmp = tmp->next;

    tmp->next = new_node;
}

void Queue::purge(){
    Node *tmp;
    while(head->next != nullptr){
        tmp = head;
        head = head->next;
        free(tmp);
    }
    tmp = head;
    head = nullptr;
    free(tmp);
}

int Queue::pop(){
    Node* tmp = head;
    int return_val = tmp->val;
    head = head->next;
    free(tmp);
    return return_val;
}

void Queue::print(){
    Node* tmp = head;

    if(head == nullptr){
        cout<<"Lista jest pusta.\n";
        return;
    }

    while(tmp != nullptr){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
}