#ifndef PWR_IV_PIAA_NODE_H
#define PWR_IV_PIAA_NODE_H

class Node {
public:
    int val;
    Node* next;
    explicit Node(int data);
    Node();
};

#endif //PWR_IV_PIAA_NODE_H