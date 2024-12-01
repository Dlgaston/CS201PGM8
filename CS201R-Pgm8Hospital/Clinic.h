//
// Created by mma99 on 11/19/2024.
//

#ifndef CLINIC_H
#define CLINIC_H

#include "LinkedList.h"


class Clinic {
public:
    LinkedList criticalList;  // List for critical patients
    LinkedList regularList;   // List for regular patients

    static const int CLINICMAXQEUESIZE = 10;
    Clinic();
    explicit Clinic(const LinkedList& critical, const LinkedList& regular);
    ~Clinic();

    int queueSize();
    void addToCrit(const Person& person);
    // void removeFromCrit(const string& social);
    // void removeFromCrit();
    void addToReg(const Person& person);
    // void removeFromReg(const string& social);
    // void removeFromReg();
    Person removeFromQueue();
    Person removeFromQueue(const string& s);
    string display();
    // New method to export clinic data for rescheduling
    string exportRemainingPatients();
};




#endif //CLINIC_H

