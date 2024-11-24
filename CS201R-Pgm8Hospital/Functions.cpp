
#include "Functions.h"

bool isDigits(string s) {
    return s.find_first_not_of("0123456789") == string::npos;
}
// Recursive function to get rid of leading 0's in social.
void formatSocial(string& s) {
    while(!s.empty() && s.at(0)=='0') {
        s = s.substr(1, s.length()-1);
        formatSocial(s);
    }
}

//Method to create new person and validate social.
Person newPerson() {
    Person person;
    string fName,lName,social;
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


void loadClinicData( ifstream& input, Clinic& heart, Clinic& pulmo, Clinic& plastic) {
    string line,token;
    while(getline(input,line)) {
        istringstream ssline(line);
        vector<string> tokens;
        while(getline(ssline,token,',')) {
            tokens.push_back(token);
        }
        string clinic = tokens[0];
        string fName = tokens[1];
        string lName = tokens[2];
        string social = tokens[3];
        formatSocial(social);
        char code = 'R';
        Person p = Person(code,fName,lName,social);
        if(clinic == "HC") {
            if(isDigits(social) && heart.queueSize()<10) {
                heart.addToReg(p);
            }

        }
        if(clinic == "PC") {
            if(isDigits(social) && pulmo.queueSize()<10) {
                pulmo.addToReg(p);
            }
        }
        if(clinic == "PSC") {
            if(isDigits(social) && plastic.queueSize()<10) {
                plastic.addToReg(p);
            }
        }
    }
}
void saveRemainingPatientsToFile(ofstream& out, Clinic& clinic, const string& clinicName, ofstream& rescheduleFile) {
    // Save remaining patients in the clinic to the transaction file
    out << "Rescheduling remaining patients in " << clinicName << ":\n";

    // Write to the reschedule CSV
    clinic.display(rescheduleFile);  // This will print out all patients remaining in the queue

    // Also add the rescheduling message to the transaction file
    out << "These patients have been rescheduled for the next day.\n\n";
}
void runClinicChoice(ofstream& out, const int& choice, Clinic& clinic, const string& clinicName, ofstream& rescheduleFile) {
    Person p,removed;
    string social;
    switch (choice) {
        case 1:
            if(clinic.queueSize() <=10) {
                cout << "Adding a patient to the "<<clinicName<<"..."<< endl;
                out << "Adding a patient to the "<<clinicName<<"..."<< endl;
                p = newPerson();
                p.setCode('R');
                clinic.addToReg(p);
                p.printPatient();
                p.printPatientToFile(out);
                out<< " was added to queue.\n"<<endl;
                cout<< " was added to queue.\n"<<endl;
                break;
            }

            cout<<"Too many patients in line.\n"<<endl;
            out<< "Too many patients in line.\n"<<endl;
        break;
        case 2:
            if(clinic.queueSize() <=10) {
                cout << "Adding a critical patient to the "<<clinicName<<"..."<< endl;
                out << "Adding a critical patient to the "<<clinicName<<"..."<< endl;
                p = newPerson();
                p.setCode('C');
                clinic.addToCrit(p);
                p.printPatient();
                p.printPatientToFile(out);
                out<< " was added to queue.\n"<<endl;
                cout<< " was added to queue.\n"<<endl;
                break;
            }
            cout<<"Too many patients in line.\n"<<endl;
            out<< "Too many patients in line.\n"<<endl;
            break;
        case 3:
            cout << "Taking out a patient for operation in the "<<clinicName<<"..." << endl;
            out << "Taking out a patient for operation in the "<<clinicName<<"..." << endl;
            if(clinic.queueSize()>0) {
                removed = clinic.removeFromQueue();
                removed.printPatient();
                removed.printPatientToFile(out);

                out<< " was removed to queue.\n"<<endl;
                cout<< " was removed to queue.\n"<<endl;
            }
            else {
                out << "Queue is empty.\n"<<endl;
                cout<< "Queue is empty.\n"<<endl;
            }
        break;
        case 4:

            cout<<"Enter Social of Patient to Cancel: "<<endl;
            cin>>social;

            while(!isDigits(social)) {
                cin.ignore();
                cout<<"Invalid social, Enter a valid social: "<<endl;
                cin>>social;
            }
            if(clinic.queueSize()>0) {
                cout << "Canceling a patient from the "<<clinicName<<"..." << endl;
                out << "Canceling a patient from the "<<clinicName<<"..." << endl;
                removed = clinic.removeFromQueue(social);
                if(removed.getSocialNumber() != social) {
                    cout<<"Patient with social "<< social<<" was not found.\n"<<endl;
                    out<<"Patient with social "<< social<<" was not found.\n"<<endl;

                }
                else {
                    removed.printPatient();
                    removed.printPatientToFile(out);
                    out<< " was removed to queue.\n"<<endl;
                    cout<< " was removed to queue.\n"<<endl;
                }
            }
            else {
                cout << "Queue is empty."<<endl;
            }

        break;
        case 5:
            cout << "Listing patients in the "<<clinicName<<" queue..." << endl;
            out << "Listing patients in the "<<clinicName<<" queue..." << endl;
            clinic.display(out);
            cout<<"\n"<<endl;
            out<<"\n"<<endl;
        break;
        case 6:
            cout << "Changing department or exiting..." << endl;
            out << "Changing department or exiting..." << endl;
            saveRemainingPatientsToFile(out, clinic, clinicName, rescheduleFile);
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