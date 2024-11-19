//
// Created by mma99 on 11/18/2024.
//

#include "Person.h"

#include <iomanip>

Person::Person() = default;

Person::Person(const string& code, const string& lastName, const string& firstName, const string& socialNumber) {
    this->code = code;
    this->lastName = lastName;
    this->firstName = firstName;
    this->socialNumber = socialNumber;
}

string Person::getCode() {
    return this->code;
}
string Person::getLastName() {
    return this->lastName;
}
string Person::getFirstName() {
    return this->firstName;
}
string Person::getSocialNumber() {
    return this->socialNumber;
}
string Person::getFullName() {

    return this->getLastName()+", "+this->getFirstName();
}

void Person::setCode(const string& code) {
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

void Person::printPatient() {
    cout<<this->getCode()<<" "<<this->getFullName()<<": "<<this->getSocialNumber()<<endl;
}
