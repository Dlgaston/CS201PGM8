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

    void addToCrit(const Person& person);
    void removeFromCrit(const string& social);
    void removeFromCrit();
    void addToReg(const Person& person);
    void removeFromReg(const string& social);
    void removeFromReg();
    void display();
};




#endif //CLINIC_H
