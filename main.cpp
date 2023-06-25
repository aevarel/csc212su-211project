#include "gradebook.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// and check that the type is of valid choice of assignment type
bool isValidType(const std::string& typeInput){
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

// also need to check that the score column is valid and not any strings
bool isValidScore(const std::string& scoreInput) {
    // exception handling to see if the scoreInput is able to be cast to float
    try {
        std::stof(scoreInput);
        return true;
    } catch (std::invalid_argument &e) {
        return false;
    }
}
/*
Type       Name          Score  --- check if line contains "Type"

Lab        Lab_1         25     --- check if the Type var is a valid choice
Assignment Assignment_1  50
                                --- make sure nothing is empty
Project1   Project_1     150    --- make sure the score can be cast into a float
Exam       Final_Exam    70
===        ===           ===    --- end the parsing once the === limits are reached
                                --- print out any of the "saved" outputs from the buffer
 */

int main(int argc, char* argv[]){
//    std::string fileName = argv[1];
    std::string fileName = "dataset1.txt";
    Gradebook gradebookObj =  Gradebook(fileName);
    std::ifstream fileIn(gradebookObj.getfileName());


    // exception handling / checking if file is opening
    if (!fileIn.is_open()) {
        std::cerr << "Couldn't open the file: " << fileName << std::endl;
        return 1;
    }
    // store the three columns of the files' data
    std::vector<std::string> types;
    std::vector<std::string> names;
    std::vector<float> scores;
    std::string line;
    while(std::getline(fileIn, line)){
        // cast the line into a string stream
        std::istringstream lineStringStream(line);
        std::string type, name, score;

        if(lineStringStream >> type >> name >> score){
            // need to check that the type and name and score are not the literals for the column names
            if (!type.empty() && !name.empty() && !score.empty()){
                // also need to check that the score column is valid and not any strings
                // and check that the type is of valid choice of assignment type
                if(isValidType(type) && isValidScore(score)){
                    // (redundant prolly) but check that each of the things are not "===" (signals end of file reading)
                    if(type == "===" || name == "===" || score == "==="){
                        // break out of all while loops, close the file, continue to the main program
                    }
                    else{
                        types.push_back(type);
                        names.push_back(name);
                        scores.push_back(std::stof(score));
                    }
                }
            }
        }
    }


    /*
     * Once file has been successfully input
     * TODO: Casting the dataSet info into deliverable objects, keeping track of the objects
     *  - initialize std::vector<*deliverable> delivPointers
     *  - cast all of the inputs into deliverable objects using the vectors of the three inputs from datafile
     *      - types, names, scores vectors from the file handling process
     *      - initialize the Type string
     *          - i.e. if deliverable->type = lab
     *              - deliverable->setScoreMax(25)
     *  - append pointers to the delivPointers vector
     *      - will be used to check the values of each of the deliverable objects we made
     *
     * TODO: main menu input
     *  - initialize masterbufferVector
     *  - print out the main menu choices
     *  - wait for input
     * TODO: 1 = deliverable section
     *      - return list of all deliverables, with names next to them
     *          - query: set or get the deliverable points?
     *              - if get
     *                  - search list of vec *deliverables->Name for inputName
     *                  - percentScore = turnPointstoPercent(*deliverable){
     *                      return this->score / this->scoreMax}
     *                  - bufferString = print out the *deliverable->score, then give the user the percentScore
     *                  - std::cout << bufferString
     *                  - ask if they want to save this bufferString to the file
     *                  - if yes{
     *                      - append bufferString to std::vector<strings> bufferVec
     *                  if input = 0{
     *                  masterbufferVector.append(all contents of bufferVec and then another row of ===========)
     *                  return to menu
     * TODO: 2 = Category Grades
     *  - initialize bufferVector
     *  - return list of the category names [Labs, Assignments, Projects, Exam]
     *         * - Assign maxPointTotal for the category names to be called on later*
     *  - wait for user input by value
     *      - maybe do 1 = labs, 2 = assignments, 3 = projects, 4 = exam
     *  - return list of deliverables->type == userInput
     *      * - since this is a repeated operation, make a function to return the deliverable-> name, gradePoints, gradePercentage
     *  - for each of the deliverables of a certain type{
     *      - sum += deliverable->grade
     *      - tempVector.append(*deliverablePtr)
     *      - buffer string >> printContents(*deliverablePtr) >> '\n' // will give us a printout of the deliverable Name->Score->gradePercentage //
     *          this is to be able to loop through the entirety of the bufferVec and print out all the stuff after appending it
     *      - bufferVec.append(bufferString)
     *    }
     *    bufferVec.append("the amount of points you have is " << sum << '/n');
     *    bufferVec.append("your total grade for the section is" << floorDivision(sum/sectionMax) '\n');
     *    for(size i : bufferVec){
     *      - std::cout << bufferVec[i]
     *  - ask user if they want to store this output into the file at the end
     *  - if(input yes){
     *      masterbufferVector.append(all contents of bufferVec and then another row of ===========)
     *      }
     *  if(input is 0){
     *  return to main menu loop}
     *
     *  TODO: 3 = Course Grades
     *   - initialize bufferVector
         - ask user what they want
            - return all individual grades, course overall points, and their overall grade percentage
            - return total scores of all categories, the overall points in each course, and their total percent grade
            - return course overall points, then the percent grade of the course
     *      - from now on, just iterate thru the tempVector list
     *  -
     *
     *
     */






    return 0;
}


