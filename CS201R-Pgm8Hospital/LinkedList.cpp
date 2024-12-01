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
    size = 0;
}
//Adds person to back of list in O1 time. Increments size by 1.
void LinkedList::addToBack(const Person& data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    //Checks if list is empty, assigns newNode to beginning of list.
    if (head == nullptr) {
        head = newNode;
    }
    //If Head is not null, but the next node is, that means the tail is empty. Assigns tail to newNode and then links to head.
    else if (head->next == nullptr) {
        tail = newNode;
        head->next = tail;
    }
    //If both tail and head are not null, assigns the node element to the current tails next pointer, then sets that new element as the new tail.
    else {
        tail->next = newNode;
        tail = tail->next;
    }
    size++;
}
//Removes header element and assigns new header to next node. Decrements size by 1.
Person LinkedList::removeFromFront() {
    Node* removed;

    // Since validation that linked list occurs before implementation, no need to check if head is null.
    removed = head;
    Person p = removed->data;
    Node* temp = head->next;
    delete head;
    head = temp;
    size--;

    return p;
}
Person LinkedList::findAndRemove(const string& s) {
    Person p;
    if (head == nullptr) {
        return p;
    }
    // Checks if the header is person being looked for, if so, removes from front.
    if (head->data.getSocialNumber() == s) {
        p = removeFromFront();
        return p;
    }
    // Since the head is already looked at, the current value will be the next.
    // Prevous value is then set up so not to break linkage in linked list.
    Node* current = head->next;
    Node* previous = head;
    while (current) {
        p = current->data;
        if (p.getSocialNumber() == s) {
            Node* deletedNode = current;
            previous->next = current->next;
            delete deletedNode;
            size--;
            return p;
        }
        previous = current;
        current = current->next;
    }
    return p;
}


int LinkedList::getSize() {
    return size;
}
string LinkedList::display() {
    string display;
    Node* current = this->head;
    while (current) {
        display += current->data.printPatient()+"\n";
        current = current->next;
    }
    return display;
}

