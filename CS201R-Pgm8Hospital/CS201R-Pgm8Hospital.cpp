// CS201R-Pgm8Hospital.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Functions.h"
#include "Clinic.h"

using namespace std;

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
    vector<string> clinicLogs(3);
    clinicLogs[0] = "HeartClinic Transaction Records: \n==============================================================\n";
    clinicLogs[1] = "PulmoClinic Transaction Records: \n==============================================================\n";
    clinicLogs[2] = "PlasticClinic Transaction Records: \n==============================================================\n";

    // Checks if the file is empty and if they want the queue line to be cleared for all clinics.
    if (!checkIfFileEmpty(rescheduleFile)) {
        char input;
        cout<< "There are is a queue in the reservation file, clear out? Y or N"<<endl;
        cin>>input;
        tolower(input);
        while (input != 'y' && input != 'n') {
            cout<<"Please enter a valid input"<<endl;
            cin>>input;
            tolower(input);
        }

        if(input=='y') {
            clearFile(rescheduleFile);
            loadClinicData(inputFile, heartClinic, pulmoClinic, plasticClinic);
        }
        else{
            loadClinicData(rescheduleFile,heartClinic,pulmoClinic,plasticClinic);
        }
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
                runClinicChoice(clinicChoice, heartClinic, "Heart Clinic",clinicLogs);
            } while (clinicChoice != 6);
            break;

        case 2: // Pulmonary Clinic
            do {
                clinicChoice = clinicMenu("Pulmonary Clinic");
                runClinicChoice(clinicChoice, pulmoClinic, "Pulmonary Clinic",clinicLogs);
            } while (clinicChoice != 6);
            break;

        case 3: // Plastic Surgery Clinic
            do {
                clinicChoice = clinicMenu("Plastic Surgery Clinic");
                runClinicChoice(clinicChoice, plasticClinic, "Plastic Surgery Clinic",clinicLogs);
            } while (clinicChoice != 6);
            break;

        case 4: // Quit
            cout << "Exiting the program. Goodbye!" << endl;

            break;
        }
    } while (mainChoice != 4);

    // Save remaining patients to rescheduled_patients.csv after the program ends
    printToCSV(rescheduleFile, heartClinic, pulmoClinic, plasticClinic);
    printClinicLogs(outputFile, clinicLogs, heartClinic, pulmoClinic, plasticClinic);
    inputFile.close();
    outputFile.close();
    rescheduleFile.close();
    return 0;
}
