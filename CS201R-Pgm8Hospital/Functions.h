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
void runClinicChoice(const int& choice, Clinic& clinic, const string& clinicName, vector<string>& clinicLogs);
void printToCSV(fstream& rescheduleFile, Clinic& heartClinic, Clinic& pulmoClinic, Clinic& plasticClinic);
void loadClinicData(fstream& input, Clinic& heart, Clinic& pulmo, Clinic& plastic);
bool checkIfFileEmpty(fstream& input);
void clearFile(fstream& input);
void printClinicLogs(ofstream& out, vector<string>& clinicLogs, Clinic& heart, Clinic& pulmo, Clinic& plastic);

#endif //FUNCTIONS_H

