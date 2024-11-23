// CS201R-Pgm8Hospital.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include "Functions.h"
#include "Clinic.h"

using namespace std;
//TODO: Create clinic class --> Clinic class will have two linked lists (Crit Pat and Reg Pat)
//TODO: Create menu options and read csv file. --> Load lists
int main()
{
    ifstream inputFile;
    ofstream outputFile;
    inputFile.open("patient.csv");
    outputFile.open("transcript.txt");

    if(!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file" << endl;
    }

    Clinic heartClinic, pulmoClinic, plasticClinic;

    loadClinicData(inputFile,heartClinic,pulmoClinic,plasticClinic);

    int mainChoice, clinicChoice;

    do {
        // Main menu
        mainChoice = mainMenu();

        switch (mainChoice) {
        case 1: // Heart Clinic
            do {
                clinicChoice = clinicMenu("Heart Clinic");
                runClinicChoice(outputFile, clinicChoice, heartClinic,"Heart Clinic");
            } while (clinicChoice != 6);
            break;

        case 2: // Pulmonary Clinic
            do {
                clinicChoice = clinicMenu("Pulmonary Clinic");
                runClinicChoice(outputFile, clinicChoice, pulmoClinic,"Pulmonary Clinic");
            } while (clinicChoice != 6);
            break;

        case 3: // Plastic Surgery Clinic
            do {
                clinicChoice = clinicMenu("Plastic Surgery Clinic");
                runClinicChoice(outputFile, clinicChoice, plasticClinic,"Plastic Surgery Clinic");
            } while (clinicChoice != 6);
            break;

        case 4: // Quit
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
    } while (mainChoice != 4);
    inputFile.close();
    outputFile.close();
    return 0;
}

 
