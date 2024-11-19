//
// Created by mma99 on 11/19/2024.
//

#include "Clinic.h"

Clinic::Clinic() = default;
Clinic::Clinic(const LinkedList& critical, const LinkedList& regular) {
    this->criticalList = critical;
    this->regularList = regular;
}
Clinic::~Clinic() = default;

//These two functions will add to back of list
void Clinic::addToCrit(const Person &person) {
    this->criticalList.addToBack(person);
}
void Clinic::addToReg(const Person &person) {
    this->regularList.addToBack(person);
}
//These two methods will remove based on social
void Clinic::removeFromCrit(const string &social) {
//TODO: Complete --> Write methods in LinkedList to search based on query
}
void Clinic::removeFromReg(const string &social) {
    //TODO: Complete --> Write methods in LinkedList to search based on query
}

//These two methods will remove from front of que.
void Clinic::removeFromCrit() {
    this->criticalList.removeFromFront();
}
void Clinic::removeFromReg() {
    this->regularList.removeFromFront();
}

void Clinic::display() {
    this->criticalList.display();
    this->regularList.display();
}


