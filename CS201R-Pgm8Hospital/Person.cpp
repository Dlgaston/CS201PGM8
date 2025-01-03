//
// Created by mma99 on 11/18/2024.
//

#include "Person.h"

// Default constructor
Person::Person() = default;

Person::Person(const char& code, const string& lastName, const string& firstName, const string& socialNumber, const string& hospital) {
    this->code = code;
    this->lastName = lastName;
    this->firstName = firstName;
    this->socialNumber = socialNumber;
    this->hospital = hospital;
}

// Accessor methods
char Person::getCode() const {
    return this->code;
}

string Person::getLastName() const {
    return this->lastName;
}

string Person::getFirstName() const {
    return this->firstName;
}

string Person::getSocialNumber() const {
    return this->socialNumber;
}

string Person::getFullName() const {
    return this->getLastName() + ", " + this->getFirstName();
}

string Person::getHospital() const {
    return this->hospital;
}

// Mutator methods
void Person::setCode(const char& code) {
    this->code = code;
}

void Person::setLastName(const string& lastName) {
    this->lastName = lastName;
}

void Person::setFirstName(const string& firstName) {
    this->firstName = firstName;
}

void Person::setSocialNumber(const string& socialNumber) {
    this->socialNumber = socialNumber;
}

void Person::setHospital(const string& hospital) {
    this->hospital = hospital;
}

// Print patient info to the console
string Person::printPatient() const {
    ostringstream patient;
    patient << setw(8) << left << this->getHospital()
        << setw(35) << left << this->getFullName()
        << setw(10) << left << this->getSocialNumber()
        << setw(5) << left << this->getCode();
    return patient.str();
}
