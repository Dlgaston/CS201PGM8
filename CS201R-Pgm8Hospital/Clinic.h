//
// Created by mma99 on 11/19/2024.
//

#ifndef CLINIC_H
#define CLINIC_H

#include "LinkedList.h"


class Clinic {
    LinkedList criticalList;
    LinkedList regularList;


    public:
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
    void display(ofstream& out);
    // New method to export clinic data for rescheduling
    void exportRemainingPatients(ofstream& rescheduleFile);
};




#endif //CLINIC_H
