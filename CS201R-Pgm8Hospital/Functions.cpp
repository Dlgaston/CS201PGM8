
#include "Functions.h"

bool isDigits(string s) {
    return s.find_first_not_of("0123456789") == string::npos;
}


//TODO: Finish loading clinic data
void loadClinicData(ifstream& input, Clinic& heart, Clinic& pulmo, Clinic& plastic) {
    string line,token;
    while(getline(input,line)) {
        istringstream ssline(line);
        vector<string> tokens;
        while(getline(ssline,token,',')) {
            tokens.push_back(token);
        }
        string clinic = tokens[0];
        if(clinic == "HC") {
            char code = 'R';
            string fName = tokens[1];
            string lName = tokens[2];
            string social = tokens[3];
            if(isDigits(social)) {
                Person p = Person(code,fName,lName,social);

            }


        }
        if(clinic == "PC") {
        }
        if(clinic == "PSC") {
        }
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