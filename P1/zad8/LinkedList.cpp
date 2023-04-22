#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList(int data){
    head = new Node(data);
}

void LinkedList::insert(int val){
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

void LinkedList::delete_node(int offset){
    Node* tmp1 = head;
    if(head == nullptr){
        cout<<"Lista jest pusta.\n";
        return;
    }

    if(head->next == nullptr){
        free(head);
        head = nullptr;
        return;
    }

    if(offset == 0){
        head = head->next;
        free(tmp1);
        return;
    }

    Node* tmp2;
    while(offset-- >= 1){
        tmp2 = tmp1;
        tmp1 = tmp1->next;
    }

    tmp2->next = tmp1->next;
    free(tmp1);
}

void LinkedList::purge(){
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

void LinkedList::print(){
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
