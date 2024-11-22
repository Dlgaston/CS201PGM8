// CS201R-Pgm8Hospital.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include "Functions.h"

using namespace std;
//TODO: Create clinic class --> Clinic class will have two linked lists (Crit Pat and Reg Pat)
//TODO: Create menu options and read csv file. --> Load lists
int main()
{
    ifstream inputFile;
    inputFile.open("patient");


    int mainChoice, clinicChoice;

    do {
        // Main menu
        mainChoice = mainMenu();

        switch (mainChoice) {
        case 1: // Heart Clinic
            do {
                clinicChoice = clinicMenu("Heart Clinic");
                switch (clinicChoice) {
                case 1:
                    cout << "Adding a patient to the Heart Clinic..." << endl;
                    break;
                case 2:
                    cout << "Adding a critical patient to the Heart Clinic..." << endl;
                    break;
                case 3:
                    cout << "Taking out a patient for operation in the Heart Clinic..." << endl;
                    break;
                case 4:
                    cout << "Canceling a patient from the Heart Clinic..." << endl;
                    break;
                case 5:
                    cout << "Listing patients in the Heart Clinic queue..." << endl;
                    break;
                case 6:
                    cout << "Changing department or exiting..." << endl;
                    break;
                }
            } while (clinicChoice != 6);
            break;

        case 2: // Pulmonary Clinic
            do {
                clinicChoice = clinicMenu("Pulmonary Clinic");
                switch (clinicChoice) {
                case 1:
                    cout << "Adding a patient to the Pulmonary Clinic..." << endl;
                    break;
                case 2:
                    cout << "Adding a critical patient to the Pulmonary Clinic..." << endl;
                    break;
                case 3:
                    cout << "Taking out a patient for operation in the Pulmonary Clinic..." << endl;
                    break;
                case 4:
                    cout << "Canceling a patient from the Pulmonary Clinic..." << endl;
                    break;
                case 5:
                    cout << "Listing patients in the Pulmonary Clinic queue..." << endl;
                    break;
                case 6:
                    cout << "Changing department or exiting..." << endl;
                    break;
                }
            } while (clinicChoice != 6);
            break;

        case 3: // Plastic Surgery Clinic
            do {
                clinicChoice = clinicMenu("Plastic Surgery Clinic");
                switch (clinicChoice) {
                case 1:
                    cout << "Adding a patient to the Plastic Surgery Clinic..." << endl;
                    break;
                case 2:
                    cout << "Adding a critical patient to the Plastic Surgery Clinic..." << endl;
                    break;
                case 3:
                    cout << "Taking out a patient for operation in the Plastic Surgery Clinic..." << endl;
                    break;
                case 4:
                    cout << "Canceling a patient from the Plastic Surgery Clinic..." << endl;
                    break;
                case 5:
                    cout << "Listing patients in the Plastic Surgery Clinic queue..." << endl;
                    break;
                case 6:
                    cout << "Changing department or exiting..." << endl;
                    break;
                }
            } while (clinicChoice != 6);
            break;

        case 4: // Quit
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
    } while (mainChoice != 4);

    return 0;
}

 
