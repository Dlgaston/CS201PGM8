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
    int size=0;

    public:

    LinkedList();
    ~LinkedList();
    void addToBack(const Person &data);
    void removeFromFront();
    int getSize();
    void display();
};



#endif //LINKEDLIST_H
