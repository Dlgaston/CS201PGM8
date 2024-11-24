//
// Created by mma99 on 11/19/2024.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Clinic.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

void loadClinicData(ifstream& input, Clinic& heart, Clinic& pulmo, Clinic& plastic);
int mainMenu();
int clinicMenu(const string& clinicName);
void runClinicChoice(ofstream& out, const int& choice, Clinic& clinic, const string& clinicName);
void printToCSV(ofstream& rescheduleFile, Clinic& heartClinic, Clinic& pulmoClinic, Clinic& plasticClinic);

#endif //FUNCTIONS_H

