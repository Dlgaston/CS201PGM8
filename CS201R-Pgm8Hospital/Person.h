//
// Created by mma99 on 11/18/2024.
//

#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

// Standard creation for Person class
class Person {
    char code;
    string lastName;
    string firstName;
    string socialNumber;
    public:
    Person();
    Person(const char& code, const string& lastName, const string& firstName, const string& socialNumber);
    char getCode();
    string getLastName();
    string getFirstName();
    string getSocialNumber();
    string getFullName();
    void setCode(const char& code);
    void setLastName(const string& lastName);
    void setFirstName(const string& firstName);
    void setSocialNumber(const string& socialNumber);
    void printPatient();

};



#endif //PERSON_H
