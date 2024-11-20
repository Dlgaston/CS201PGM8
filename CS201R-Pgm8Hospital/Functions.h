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

void loadClinicData(const ifstream& input, Clinic& heart, Clinic& pulmo, Clinic& plastic);

#endif //FUNCTIONS_H
