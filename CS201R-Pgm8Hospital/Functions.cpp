
#include "Functions.h"

bool isDigits(string s) {
    return s.find_first_not_of("0123456789") == string::npos;
}


//TODO: Finish loading clinic data
void loadClinicData(ifstream &input, Clinic &heart, Clinic &pulmo, Clinic &plastic) {
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

