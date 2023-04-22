#include "Node.h"

Node::Node(int data){
    this->val = data;
    this->next = nullptr;
}

Node::Node(){
    this->val = 0;
    this->next = nullptr;
}