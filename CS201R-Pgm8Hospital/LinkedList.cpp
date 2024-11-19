//
// Created by mma99 on 11/18/2024.
//

#include "LinkedList.h"

LinkedList::LinkedList() = default;

LinkedList::~LinkedList() {
    Node* current = head;
    Node* next;
    while (current) {
        next = current->next;
        delete current;
        current = next;
    }
}
//Adds person to back of list in O1 time.
void LinkedList::add(const Person &data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    //Checks if list is empty, assigns newNode to beginning of list.
    if(head == nullptr) {
        head = newNode;
    }
    //If Head is not null, but the next node is, that means the tail is empty. Assigns tail to newNode and then links to head.
    else if(head->next == nullptr) {
        tail = newNode;
        head->next = tail;
    }
    //If both tail and head are not null, assigns the node element to the current tails next pointer, then sets that new element as the new tail.
    else {
        tail->next = newNode;
        tail = tail->next;
    }
}

void LinkedList::display() {
    Node* current = this->head;
    while(current) {
        head->data.printPatient()<<endl;
    }
}

