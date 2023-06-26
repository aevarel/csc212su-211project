#include <vector>
#include <iostream>
#include <fstream>
#include <iostream>
#include <cmath>
#include "gradebook.h"

Gradebook::Gradebook(std::string fileName){
    // set the file name type
    setfileName(fileName);
}

std::string Gradebook::getfileName() {
    return this->fileName;
}
void Gradebook::generateGradebookPtrs(const std::vector<std::string>& types, const std::vector<std::string>& names, const std::vector<float>& scores){
    // generates deliverable objects for the vectors given from the file handling

    for(int i = 0; i < types.size(); i++){
        Deliverable* deliverable = new Deliverable(names[i], types[i], scores[i]);
        this->gradebookPtrs.push_back(deliverable);
    }
}
// will be used to search the gradebook for deliverable objects that match the name
// returns a list of the ptrs to the objects matching the name entered
std::vector<Deliverable*> Gradebook::searchGradebookName(std::string name) {
    std::vector<Deliverable*> gradebookPtrsSelection;
    for (auto & gradebookPtr : this->gradebookPtrs) {
        if(gradebookPtr->getName() == name){
            gradebookPtrsSelection.push_back(gradebookPtr);
        }
    }
    return gradebookPtrsSelection;
}
// will be used to search the gradebook for deliverable objects that match the TYPE
// basically the same as above but different implementation
std::vector<Deliverable*> Gradebook::searchGradebookType(std::string type) {
    std::vector<Deliverable*> gradebookPtrsSelection;
    for (auto & gradebookPtr : this->gradebookPtrs) {
        if(gradebookPtr->getCategory() == type){
            gradebookPtrsSelection.push_back(gradebookPtr);
        }
    }
    return gradebookPtrsSelection;
}
// can be paired with the above 2 functions to get a list printed of all of the deliverable objects as above
// if not paired, i could just push in the this->gradebookPtrs vector to get a printout of all of the grades in the gradebook
void Gradebook::printGradebookSelection(std::vector<Deliverable*> gradebookPtrs){
    std::cout << "========================\n";
    for (auto & gradebookPtr : gradebookPtrs) {
        std::cout << "| " << gradebookPtr->getName() << " | " << gradebookPtr->getGrade() << " |\n";
    }
    std::cout << "========================\n";
}

// this will be given a section, either some or all of the deliverables, and sum the points
// WILL NOT COMPARE AGAINST SECTION MAX
int Gradebook::sumPoints(std::vector<Deliverable*> gradebookPtrs){
    int points = 0;
    for(auto &deliv: gradebookPtrs){
        points += deliv->getGrade();
    }
    return points;
}
// will take in the amount of points in the deliverable objects
// compare them against the point total for the category member var in gradebook
// and then return it with 2 sig figs
float Gradebook::calculatePercentScore(int points, std::string category){
    // get the categoryMax score based on the string passed in
    float categoryMax = this->getCategoryMax(category);
    // divide the points by the category max, rounding to two decimal points
    double percentage = ((points / categoryMax) * 100);
    // if the result is higher than the categoryMax, then effectively round to 100 by returning a percentage of 100
    if(percentage > 100){
        percentage = 100;
    }
    return percentage;
}
// gives us the category max that we need for each category being analyzed
float Gradebook::getCategoryMax(std::string category){
    float categoryScoreMax = 0;
    if(category == "Lab"){
        categoryScoreMax = 200;
    }
    if(category == "Assignment"){
        categoryScoreMax = 200;
    }
    if(category == "Project"){
        categoryScoreMax = 500;
    }
    if(category == "Exam"){
        categoryScoreMax = 100;
    }
    if(category == "All"){
        categoryScoreMax = 1000;
    }
    return categoryScoreMax;
}


void Gradebook::setfileName(const std::string& name){
    this->fileName = name;
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

