//
// Created by mma99 on 11/18/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Person.h"

// Node struct to contain person data and pointer to next node location of data.
struct Node {
    Person data;
    Node *next=nullptr;
};

class LinkedList {
    Node *head=nullptr;
    Node *tail=nullptr;

    public:
    LinkedList();
    ~LinkedList();
    void add(const Person &data);
    void display();
};



#endif //LINKEDLIST_H
