#include <iostream>
#include <string>
using namespace std;

struct list_node{
    int val;
    list_node* next;
    explicit list_node(int value){
        val = value;
        next = nullptr;
    }
};

void list_insert(list_node*& prev_node, int val){
    auto* new_node = new list_node(val);
    auto tmp = prev_node;
    if(prev_node == nullptr) {
        prev_node = new_node;
        return;
    }
    while(tmp->next != nullptr)
        tmp = tmp->next;
    tmp->next = new_node;
}

void delete_list(list_node** head){
    list_node* this_node = *head;
    list_node* next_node;

    while(this_node != nullptr){
        next_node = this_node->next;
        free(this_node);
        this_node = next_node;
    }
    *head = nullptr;
}

void delete_node(list_node*& head, int num){
    list_node* tmp = head, *to_del;
    for(int i = 0; i < num - 2; i++)
        tmp = tmp->next;
    to_del = tmp->next;
    tmp->next = to_del->next;
    delete to_del;
}

void print_list(list_node* node){
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
    auto* head = new list_node(1);

    list_insert(head, 99);
    list_insert(head, 2);
    list_insert(head, 0);

    cout<<"Before\n";
    print_list(head);

    cout<<"\nAfter deletion\n";
    delete_node(head, 2);
    print_list(head);

    cout<<"\nSecond print:\n";
    delete_list(&head);
    print_list(head);

    cout<<"\nNew list print:\n";
    list_insert(head, 1);
    list_insert(head, 2);
    list_insert(head, 99);
    print_list(head);
    cout<<"\nNew list after del print:\n";
    delete_node(head, 3);
    print_list(head);

    return 0;
}