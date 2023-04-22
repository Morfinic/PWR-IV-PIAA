#include <iostream>
#include <string>
using namespace std;

struct queue_node{
    int val;
    queue_node* next;
    explicit queue_node(int value){
        val = value;
        next = nullptr;
    }
};

void queue_push(queue_node*& prev_node, int val){
    auto* new_node = new queue_node(val);
    auto tmp = prev_node;
    if(prev_node == nullptr) {
        prev_node = new_node;
        return;
    }
    while(tmp->next != nullptr)
        tmp = tmp->next;
    tmp->next = new_node;
}

void queue_purge(queue_node*& head){
    queue_node* this_node = head;
    queue_node* next_node;

    while(this_node != nullptr){
        next_node = this_node->next;
        delete this_node;
        this_node = next_node;
    }
    head = nullptr;
}

int queue_pop(queue_node*& head){
    queue_node* tmp = head;
    auto return_val = head->val;
    head = head->next;
    delete tmp;
    return return_val;
}

void print_queue(queue_node* node){
    if(node == nullptr) {
        cout<<"Lista jest pusta.\n";
        return;
    }
    while(node != nullptr){
        cout<<node->val<<" ";
        node = node->next;
    }
}

int main(){
    cout<<"Queue print: \n";
    auto* queue = new queue_node(1);
    queue_push(queue, 2);
    queue_push(queue, 3);
    queue_push(queue, 4);
    queue_push(queue, 5);
    print_queue(queue);

    cout<<"Queue pop print: \n";
    cout<<"Popped: "<<queue_pop(queue)<<"\n";
    print_queue(queue);

    cout<<"Queue purge print: \n";
    queue_purge(queue);
    print_queue(queue);

    cout<<"New queue print: \n";
    queue_push(queue, 0);
    queue_push(queue, 10);
    queue_push(queue, 20);
    queue_push(queue, 30);
    print_queue(queue);

    cout<<"New queue pop print: \n";
    cout<<"Popped: "<<queue_pop(queue)<<"\n";
    print_queue(queue);

    return 0;
}