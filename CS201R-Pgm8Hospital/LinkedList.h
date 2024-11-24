//
// Created by mma99 on 11/18/2024.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Person.h"

// Node struct to contain person data and pointer to next node location of data.
struct Node {
    Person data;
    Node* next = nullptr;
};

class LinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    LinkedList();
    ~LinkedList();
    void addToBack(const Person& data);
    Person removeFromFront();
    Person findAndRemove(const string& s);
    int getSize();
    void display(ofstream& out);
};



#endif //LINKEDLIST_H
