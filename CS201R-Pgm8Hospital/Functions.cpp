
#include "Functions.h"

bool isDigits(string s) {
    return s.find_first_not_of("0123456789") == string::npos;
}
bool checkIfFileEmpty(fstream& file) {
    file.seekg(0, ios::end);
    cout<<file.tellg()<<endl;
    return file.tellg() == 0;
}
//Clears out file to empty
void clearFile(fstream &file) {
    if (file.is_open()) {
        file.close();
    }

    // Reopen the file in truncation mode to clear its contents
    file.open("rescheduled_patients.csv", ios::out | ios::trunc);
    if (!file) {
        cerr << "Error: Could not open file." << endl;
    }
}

// Recursive function to get rid of leading 0's in social.
void formatSocial(string& s) {
    while (!s.empty() && s.at(0) == '0') {
        s = s.substr(1, s.length() - 1);
        formatSocial(s);
    }
}

//Method to create new person and validate social.
Person newPerson() {
    Person person;
    string fName, lName, social;
    bool validSocial = false;

    cout << "Enter first name: ";
    cin >> fName;
    cin.ignore();
    cout << "Enter last name: ";
    cin >> lName;
    cin.ignore();
    while (!validSocial) {
        cout << "Enter social: ";
        cin >> social;
        cin.ignore();
        validSocial = isDigits(social);
        formatSocial(social);
        if (!validSocial || social.empty()) {
            validSocial = false;
            cout << "Invalid Social. Please try again." << endl;
        }
    }
    person.setFirstName(fName);
    person.setLastName(lName);
    person.setSocialNumber(social);
    return person;
}


void loadClinicData(ifstream& input, Clinic& heart, Clinic& pulmo, Clinic& plastic) {
    string line, token;
    while (getline(input, line)) {
        istringstream ssline(line);
        vector<string> tokens;
        while (getline(ssline, token, ',')) {
            tokens.push_back(token);
        }
        string clinic = tokens[0];
        string fName = tokens[1];
        string lName = tokens[2];
        string social = tokens[3];
        formatSocial(social);
        char code = 'R';
        Person p = Person(code, fName, lName, social);
        if (clinic == "HC") {
            if (isDigits(social) && heart.queueSize() < 10) {
                p.setHospital("HC");
                heart.addToReg(p);
            }

        }
        if (clinic == "PC") {
            if (isDigits(social) && pulmo.queueSize() < 10) {
                p.setHospital("PC");
                pulmo.addToReg(p);
            }
        }
        if (clinic == "PSC") {
            if (isDigits(social) && plastic.queueSize() < 10) {
                p.setHospital("PSC");
                plastic.addToReg(p);
            }
        }
    }
}

void addToCritOrReg(Clinic& clinic,Person& p) {
    if (p.getCode()=='R') {
        clinic.addToReg(p);
    }
    else if (p.getCode()=='C') {
        clinic.addToCrit(p);
    }
}

//Overloaded function to hand fstream file resheduled_patients
void loadClinicData(fstream& file, Clinic& heart, Clinic& pulmo, Clinic& plastic) {
    file.seekg(0, ios::beg);
    string line, token;
    while (getline(file, line)) {
        istringstream ssline(line);
        vector<string> tokens;

        // Split line by commas and store tokens
        while (getline(ssline, token, ',')) {
            tokens.push_back(token);
        }

        // Ensure correct token size (5: Clinic, First Name, Last Name, Social Number, Code)
        if (tokens.size() != 5) {
            cerr << "Invalid data format: " << line << " (expected 5 tokens)" << endl;
            continue;
        }

        // Extract patient details
        string clinic = tokens[0];
        string fName = tokens[1];
        string lName = tokens[2];
        string social = tokens[3];
        string code = tokens[4];

        // Validate code
        if (code != "R" && code != "C") {
            cerr << "Invalid code in line: " << line << " (expected 'R' or 'C')" << endl;
            continue;
        }

        // Remove leading zeros from the social number
        formatSocial(social);

        // Create Person object
        Person p(code[0], lName, fName, social,clinic);

        // Add the patient to the appropriate clinic's queue
        if (clinic == "HC") {
            addToCritOrReg(heart, p);
        }
        else if (clinic == "PC") {
            addToCritOrReg(pulmo, p);
        }
        else if (clinic == "PSC") {
            addToCritOrReg(plastic, p);
        }
        else {
            cerr << "Unknown clinic in line: " << clinic << endl;
        }
    }
}


void runClinicChoice(ofstream& out, const int& choice, Clinic& clinic, const string& clinicName) {
    Person p, removed;
    string social;
    switch (choice) {
    case 1:
        if (clinic.queueSize() < 10) {
            cout << "Adding a patient to the " << clinicName << "..." << endl;
            out << "Adding a patient to the " << clinicName << "..." << endl;
            p = newPerson();
            p.setCode('R');
            clinic.addToReg(p);
            p.printPatient();
            p.printPatientToFile(out);
            out << " was added to queue.\n" << endl;
            cout << " was added to queue.\n" << endl;
            break;
        }

        cout << "Too many patients in line.\n" << endl;
        out << "Too many patients in line.\n" << endl;
        break;
    case 2:
        if (clinic.queueSize() < 10) {
            cout << "Adding a critical patient to the " << clinicName << "..." << endl;
            out << "Adding a critical patient to the " << clinicName << "..." << endl;
            p = newPerson();
            p.setCode('C');
            clinic.addToCrit(p);
            p.printPatient();
            p.printPatientToFile(out);
            out << " was added to queue.\n" << endl;
            cout << " was added to queue.\n" << endl;
            break;
        }
        cout << "Too many patients in line.\n" << endl;
        out << "Too many patients in line.\n" << endl;
        break;
    case 3:
        cout << "Taking out a patient for operation in the " << clinicName << "..." << endl;
        out << "Taking out a patient for operation in the " << clinicName << "..." << endl;
        if (clinic.queueSize() > 0) {
            removed = clinic.removeFromQueue();
            removed.printPatient();
            removed.printPatientToFile(out);

            out << " was removed to queue.\n" << endl;
            cout << " was removed to queue.\n" << endl;
        }
        else {
            out << "Queue is empty.\n" << endl;
            cout << "Queue is empty.\n" << endl;
        }
        break;
    case 4:

        cout << "Enter Social of Patient to Cancel: " << endl;
        cin >> social;

        while (!isDigits(social)) {
            cin.ignore();
            cout << "Invalid social, Enter a valid social: " << endl;
            cin >> social;
        }
        if (clinic.queueSize() > 0) {
            cout << "Canceling a patient from the " << clinicName << "..." << endl;
            out << "Canceling a patient from the " << clinicName << "..." << endl;
            removed = clinic.removeFromQueue(social);
            if (removed.getSocialNumber() != social) {
                cout << "Patient with social " << social << " was not found.\n" << endl;
                out << "Patient with social " << social << " was not found.\n" << endl;

            }
            else {
                removed.printPatient();
                removed.printPatientToFile(out);
                out << " was removed to queue.\n" << endl;
                cout << " was removed to queue.\n" << endl;
            }
        }
        else {
            cout << "Queue is empty." << endl;
        }

        break;
    case 5:
        cout << "Listing patients in the " << clinicName << " queue..." << endl;
        out << "Listing patients in the " << clinicName << " queue..." << endl;
        clinic.display(out);
        cout << "\n" << endl;
        out << "\n" << endl;
        break;
    case 6:
        cout << "Changing department or exiting..." << endl;
        out << "Changing department or exiting..." << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
    }
}

int mainMenu() {
    int choice;
    bool validInput = false;

    while (!validInput) {
        try {

            cout << "=======================================" << endl;
            cout << "           KC RESEARCH HOSPITAL        " << endl;
            cout << "=======================================" << endl;
            cout << "1: Heart Clinic" << endl;
            cout << "2: Pulmonary Clinic" << endl;
            cout << "3: Plastic Surgery" << endl;
            cout << "4: Quit" << endl;
            cout << "=======================================" << endl;
            cout << "Enter your choice (1-4): ";

            string input;
            cin >> input;

            choice = stoi(input);

            if (choice < 1 || choice > 4) {
                throw out_of_range("Choice is out of range.");
            }

            validInput = true;
        }
        catch (const invalid_argument&) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
        }
        catch (const out_of_range&) {
            cout << "Invalid choice. Please select a number between 1 and 4." << endl;
        }
    }

    return choice;
}
int clinicMenu(const string& clinicName) {
    int choice;
    bool validInput = false;

    while (!validInput) {
        try {

            cout << "=======================================" << endl;
            cout << "      Welcome to the " << clinicName << endl;
            cout << "=======================================" << endl;
            cout << "1: - Add Patient" << endl;
            cout << "2: - Add Critical Patient" << endl;
            cout << "3: - Take Out Patient for Operation" << endl;
            cout << "4: - Cancel Patient" << endl;
            cout << "5: - List Patients in Queue" << endl;
            cout << "6: - Change Department or Exit" << endl;
            cout << "=======================================" << endl;
            cout << "Enter your choice (1-6): ";

            string input;
            cin >> input;

            choice = stoi(input);

            if (choice < 1 || choice > 6) {
                throw out_of_range("Choice is out of range.");
            }

            validInput = true;
        }
        catch (const invalid_argument&) {
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
        }
        catch (const out_of_range&) {
            cout << "Invalid choice. Please select a number between 1 and 6." << endl;
        }
    }

    return choice;
}
void printToCSV(fstream& rescheduleFile, Clinic& heartClinic, Clinic& pulmoClinic, Clinic& plasticClinic) {
    clearFile(rescheduleFile);
    // Helper lambda function to print patients from each clinic
    auto printClinicPatients = [&](LinkedList& list, const string& clinicAbbreviation) {
        Node* current = list.head;  // Access the head of the LinkedList
        while (current != nullptr) {
            Person& p = current->data;
            rescheduleFile << clinicAbbreviation << ","  // Clinic abbreviation at the front
                << p.getFirstName() << ","
                << p.getLastName() << ","
                << p.getSocialNumber() << ","
                << p.getCode() << "\n";  // Print patient details
            current = current->next;
        }
        };

    // Print patients for each clinic (Heart, Pulmonary, and Plastic Surgery Clinics)
    printClinicPatients(heartClinic.criticalList, "HC");  // Heart Clinic abbreviation
    printClinicPatients(heartClinic.regularList, "HC");
    printClinicPatients(pulmoClinic.criticalList, "PC");  // Pulmonary Clinic abbreviation
    printClinicPatients(pulmoClinic.regularList, "PC");
    printClinicPatients(plasticClinic.criticalList, "PSC");  // Plastic Surgery Clinic abbreviation
    printClinicPatients(plasticClinic.regularList, "PSC");
}
