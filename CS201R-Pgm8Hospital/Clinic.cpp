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
void Clinic::addToCrit(const Person& person) {
    this->criticalList.addToBack(person);
}
void Clinic::addToReg(const Person& person) {
    this->regularList.addToBack(person);
}
Person Clinic::removeFromQueue() {
    Person removed;
    if (this->criticalList.getSize() == 0) {
        removed = this->regularList.removeFromFront();
    }
    else {
        removed = this->criticalList.removeFromFront();
    }
    return removed;
}

//Searches crit and reg list to find patient. If removed comes back empty from crit -> Searches regList.
Person Clinic::removeFromQueue(const string& s) {
    Person removed;
    removed = this->criticalList.findAndRemove(s);
    if (removed.getSocialNumber() != s) {
        removed = this->regularList.findAndRemove(s);
    }
    return removed;
}

// Returns the size of the hospital queue.
int Clinic::queueSize() {
    return this->criticalList.getSize() + this->regularList.getSize();
}

string Clinic::display() {
    string display;
    if (this->criticalList.getSize() > 0 || this->regularList.getSize() > 0) {
        display += this->criticalList.display();
        display += this->regularList.display();
    }
    else {
        display += "No patients in queue.\n";
    }
    return display;
}
string Clinic::exportRemainingPatients() {
    string display;
    display +=this->criticalList.display();
    display +=this->regularList.display();
    return display;
}


