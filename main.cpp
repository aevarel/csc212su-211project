#include "gradebook.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>

// and check that the type is of valid choice of assignment type
bool isValidType(const std::string& typeInput){
    // list of valid assignment type choices
    const std::string validTypes[] = {"Lab", "Assignment", "Project", "Exam"};
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

// handle every input so that it falls between the range of the selections of the menu, will be used differently each time it is called essentially to take in input with correct ranges

int inputHandleRange(int fromNumber, int toNumber){
    int input;
    while(true){
    std::cout << "Input: ";
    // essentially handles the case where the input data passed through the input stream cannot be cast into an integer value
    if(!(std::cin >> input)){
        std::cout << "Invalid input, please enter a valid option.\n";
        // need to include this so that every other character included in the stream isnt considered
        // and thus the std::cout is repeated for every character T_T
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if(input < fromNumber || input > toNumber){
        std::cout << "Invalid input, please enter an integer from " << fromNumber << " to " << toNumber << ".\n";
    }
    else{
        break;
    }
    }
    return input;
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


// TODO:
//      - rework the printGradebookSelection into returning a variable which contains all of the contents of the printing to be printed
//         - concatenate them all into a buffer statement
        // - append these statements into one masterBuffer
        // - print back into the datasetfile or another file at end of program
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

        if(lineStringStream >> type >> name >> score) {
            // need to check that the type and name and score are not the literals for the column names
            if (!type.empty() && !name.empty() && !score.empty()) {
                // also need to check that the score column is valid and not any strings
                // and check that the type is of valid choice of assignment type
                if (isValidType(type) && isValidScore(score)) {
                    // (redundant prolly) but check that each of the things are not "===" (signals end of file reading)
                    if (type == "===" || name == "===" || score == "===") {
                        // break out of all while loops, close the file, continue to the main program
                    } else {
                        types.push_back(type);
                        names.push_back(name);
                        scores.push_back(std::stof(score));
                    }
                }
            }
        }
    }
    // takes the three vectors we just filled and generates deliverable objects with them
    gradebookObj.generateGradebookPtrs(types, names, scores);

    // initialize the main menu choice variables
    int gradebookMenuChoice;
    /*
    * TODO: main menu input
    *  - wait for input
    */
    // - initialize masterbufferVector
    // will append the strings that need to be written to the input file at the end of the menu
    std::vector<std::string> masterbufferVector;

    while (true) {
        gradebookObj.printGradebookSelection(gradebookObj.gradebookPtrs);
        // - print out the main menu choices
        std::cout << "Main Menu:\n0. Exit\n1. Modify Deliverable \n2. Category Grades\n3. Course Grades \n";
        // - wait for input
        gradebookMenuChoice = inputHandleRange(0, 3);
        if(gradebookMenuChoice == 0){
            // Exit the program
            break;
        }
        else if(gradebookMenuChoice == 1){
            std::cout << "\nModifying Deliverable\n\n Please enter the exact name of the deliverable that you would like to modify.\n*CaSe sensitive*\n";
            while(true){
                // Change the grade of a deliverable
                // Search by the value of the name
                std::cout << "Input: ";
                std::string nameDeliverable;
                std::cin >> nameDeliverable;

                std::vector<Deliverable *> delivPtrs = gradebookObj.searchGradebookName(nameDeliverable);
                if (delivPtrs.empty()) {
                    std::cout << "The deliverable you have entered is not a valid name, please try again.\n";
                    continue;
                } else {
                    while(true){
                        std::cout << "1. Set Deliverable Name\n2. Set Deliverable Grade\n";
                        gradebookMenuChoice = inputHandleRange(1,2);
                        if(gradebookMenuChoice == 1){

                            std::string newName;
                            std::cout << "What would you like the new name of the deliverable to be?\nInput: ";
                            std::cin >> newName;

                            // Set the name of the deliverable
                            std::cout << "\nThe new name of " << delivPtrs[0]->getName() << " is " << newName << "\n\n";
                            delivPtrs[0]->setName(newName);
                            break;}
                        if(gradebookMenuChoice == 2) {
                            float deliverableGrade;
                            std::cout << "What would you like the new grade of the deliverable to be?\nInput: ";
                            std::cin >> deliverableGrade;

                            // Set the grade of the deliverable
                            std::cout << "\nThe new grade of " << delivPtrs[0]->getGrade() << " is " << deliverableGrade << "\n\n";
                            delivPtrs[0]->setGrade(deliverableGrade);
                            break;}
                        }
                    }
                break;
                }
            }
        else if(gradebookMenuChoice == 2){
            // ask the user for the category
            std::cout << "\nPrinting Category Grades\n\n Please enter the name of the category you would like to see your grades for.\n"
                    << "Categories: \n - 'Assignment'\n - 'Lab'\n - 'Project'\n - 'Exam'\nEnter 'exit' to return to the main menu.\n";
            while(true){
                std::cout << "Input: ";
                std::string categoryName;
                std::cin >> categoryName;
                // allow the user to enter 0 to return to the main menu here
                if(categoryName == "exit"){
                    break;
                }
                std::vector<Deliverable *> delivPtrs = gradebookObj.searchGradebookType(categoryName);
                if (delivPtrs.empty()) {
                    std::cout << "The deliverable you have entered is not a valid name, please try again.\n";
                    continue;
                } else {
                    while(true){
                        std::cout << "Grades for " << categoryName << " deliverables:\n";
                        gradebookObj.printGradebookSelection(delivPtrs);
                        // call sumPoints for the delivPtrs to get the sum of all of the points
                        int sectionPts = gradebookObj.sumPoints(delivPtrs);
                        // print sumPoints | percentageScore
                        // then pass in the result of sumPoints into calculatePercentScore to get the percentage of whatever section we're calculating
                        std::cout << "| Total Points Earned = " << sectionPts << " |\n";
                        std::cout << "| Final Section Percentage = " << gradebookObj.calculatePercentScore(sectionPts, categoryName) << " |\n\n";
                        break;
                    }
                    }
                break;
            }
        }
        else if(gradebookMenuChoice == 3){
            std::string categoryTypes[] = {"Lab", "Assignment", "Project", "Exam"};
            std::cout << "Course Grades\n\nWhich of the following course overall grades would you like to view?\n\n0. Exit\n1. All Grades within respective categories and course overall\n2. All Category totals and course overall\n3. Only Course Overall\n";
            while(true){
                gradebookMenuChoice =  inputHandleRange(0, 3);
                // exit to the main menu
                if(gradebookMenuChoice == 0){
                    break;
                }
                // All Grades within respective categories and course overall
                if(gradebookMenuChoice == 1){
                    for(auto &type : categoryTypes){
                        std::cout <<"\n" << type << " Grades\n";
                        // will be used to sum the points up of each of the
                        std::vector<Deliverable*> iterativeDeliverables = gradebookObj.searchGradebookType(type);
                        gradebookObj.printGradebookSelection(iterativeDeliverables);
                        int sectionPts = gradebookObj.sumPoints(iterativeDeliverables);
                        std::cout << "| Total Points of the Section = " << sectionPts << " |\n";
                        std::cout << "| Section Percentage = " << gradebookObj.calculatePercentScore(sectionPts, type) << " |\n";

                    }
                    // final overall summary of the grades from all of the deliverables
                    int sectionPtsAll = gradebookObj.sumPoints(gradebookObj.gradebookPtrs);
                    std::cout << "| Course Points Overall = " << sectionPtsAll << " |\n";
                    std::cout << "| Overall Percentage = " << gradebookObj.calculatePercentScore(sectionPtsAll, "All") << " |\n\n";
                }
                // All Category totals and course overall
                if(gradebookMenuChoice == 2){
                    for(auto &type : categoryTypes) {
                        std::vector<Deliverable *> iterativeDeliverables = gradebookObj.searchGradebookType(type);
                        int sectionPts = gradebookObj.sumPoints(iterativeDeliverables);
                        std::cout << "| Total Points of the "<< type << " Section = " << sectionPts << " |\n";
                        std::cout << "| " << type << " Section Percentage = " << gradebookObj.calculatePercentScore(sectionPts, type)
                                  << " |\n";
                    }
                    int sectionPtsAll = gradebookObj.sumPoints(gradebookObj.gradebookPtrs);
                    std::cout << "| Course Points Overall = " << sectionPtsAll << " |\n";
                    std::cout << "| Overall Percentage = " << gradebookObj.calculatePercentScore(sectionPtsAll, "All") << " |\n\n";
                }
                // Only Course Overall
                if(gradebookMenuChoice == 3){
                    int points = gradebookObj.sumPoints(gradebookObj.gradebookPtrs);
                    std::cout << "========================\n| Total Points Earned = " << points << " |\n";
                    std::cout << "| Course Overall Grade = " << gradebookObj.calculatePercentScore(points, "All") << " |\n========================\n\n";
                }
                break;
            }
        }
    }

        // modify the grade of the deliverable instead



    /*
     * Once file has been successfully input
     * TODO: 1 = deliverable section
     *                  - bufferString = print out the *deliverable->score, then give the user the percentScore
     *                  - std::cout << bufferString
     *                  - ask if they want to save this bufferString to the file
     *                  - if yes{
     *                      - append bufferString to std::vector<strings> bufferVec
     *                  if input = 0{
     *                  masterbufferVector.append(all contents of bufferVec and then another row of ===========)
     *                  return to menu
     *
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
                - if this{
                    -
            - return total scores of all categories, the overall points in each course, and their total percent grade
            - return course overall points, then the percent grade of the course


     *
     *
     */






    return 0;
    }