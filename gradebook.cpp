#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include "gradebook.h"

Gradebook::Gradebook(std::string fileName){
    // set the file name type
    setfileName(fileName);
}

std::string Gradebook::getfileName() {
    return this->fileName;
}

void Gradebook::setfileName(const std::string& name){
    this->fileName = name;
    return;
}

// also need to check that the score column is valid and not any strings
bool Gradebook::isValidScore(const std::string &scoreInput) {
    // exception handling to see if the scoreInput is able to be cast to float
    try {
        std::stof(scoreInput);
        return true;
    } catch (std::invalid_argument &e) {
        return false;
    }
}

// and check that the type is of valid choice of assignment type
bool Gradebook::isValidType(const std::string &typeInput) {
    // list of valid assignment type choices
    const std::string validTypes[] = {"Lab", "Assignment", "Project1", "Project2", "Exam"};
    // parse thru the validTypes array, check if the typeInput is in the array
    for(const std::string& types : validTypes){
        if(typeInput == types){
            // input type is in array
            return true;
        }
    }
    return false;
}


