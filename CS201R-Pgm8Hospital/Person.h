//
// Created by mma99 on 11/18/2024.
//

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

// Standard creation for Person class
class Person {
    string code;
    string lastName;
    string firstName;
    string socialNumber;
    public:
    Person();
    Person(const string& code, const string& lastName, const string& firstName, const string& socialNumber);
    string getCode();
    string getLastName();
    string getFirstName();
    string getSocialNumber();
    string getFullName();
    void setCode(const string& code);
    void setLastName(const string& lastName);
    void setFirstName(const string& firstName);
    void setSocialNumber(const string& socialNumber);
    void printPatient();

};



#endif //PERSON_H
