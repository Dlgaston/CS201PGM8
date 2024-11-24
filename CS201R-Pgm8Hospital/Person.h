//
// Created by mma99 on 11/18/2024.
//

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Person {
private:
    char code;                // 'R' for regular, 'C' for critical
    string firstName;
    string lastName;
    string socialNumber;
    string hospital;          // New attribute to store the hospital name

public:
    Person();
    Person(const char& code, const string& lastName, const string& firstName, const string& socialNumber, const string& hospital="");

    // Accessors and Mutators
    char getCode() const;
    string getLastName() const;
    string getFirstName() const;
    string getSocialNumber() const;
    string getFullName() const;
    string getHospital() const;
    void setCode(const char& code);
    void setLastName(const string& lastName);
    void setFirstName(const string& firstName);
    void setSocialNumber(const string& socialNumber);
    void setHospital(const string& hospital);  // New setter for the hospital

    // Methods to print patient information
    void printPatient() const;
    void printPatientToFile(ofstream& fout) const;
};

#endif // PERSON_H
