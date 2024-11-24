// CS201R-Pgm8Hospital.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Functions.h"
#include "Clinic.h"

using namespace std;

bool checkIfFileEmpty(fstream& file) {
    file.seekg(0, ios::end);
    return file.tellg() == 0;
}

int main() {
    ifstream inputFile;
    ofstream outputFile;
    fstream rescheduleFile;

    inputFile.open("patient.csv");
    outputFile.open("transcript.txt");
    rescheduleFile.open("rescheduled_patients.csv", ios::in | ios::out);



    if (!inputFile.is_open() || !outputFile.is_open()|| !rescheduleFile.is_open()) {
        cerr << "Error opening file" << endl;
    }

    Clinic heartClinic, pulmoClinic, plasticClinic;

    if (!checkIfFileEmpty(rescheduleFile)) {
        loadClinicData(rescheduleFile,heartClinic,pulmoClinic,plasticClinic);
    }
    else{loadClinicData(inputFile, heartClinic, pulmoClinic, plasticClinic);}
    int mainChoice, clinicChoice;

    do {
        // Main menu
        mainChoice = mainMenu();

        switch (mainChoice) {
        case 1: // Heart Clinic
            do {
                clinicChoice = clinicMenu("Heart Clinic");
                runClinicChoice(outputFile, clinicChoice, heartClinic, "Heart Clinic");
            } while (clinicChoice != 6);
            break;

        case 2: // Pulmonary Clinic
            do {
                clinicChoice = clinicMenu("Pulmonary Clinic");
                runClinicChoice(outputFile, clinicChoice, pulmoClinic, "Pulmonary Clinic");
            } while (clinicChoice != 6);
            break;

        case 3: // Plastic Surgery Clinic
            do {
                clinicChoice = clinicMenu("Plastic Surgery Clinic");
                runClinicChoice(outputFile, clinicChoice, plasticClinic, "Plastic Surgery Clinic");
            } while (clinicChoice != 6);
            break;

        case 4: // Quit
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
    } while (mainChoice != 4);

    // Save remaining patients to rescheduled_patients.csv after the program ends
    printToCSV(rescheduleFile, heartClinic, pulmoClinic, plasticClinic);

    inputFile.close();
    outputFile.close();
    rescheduleFile.close();
    return 0;
}
