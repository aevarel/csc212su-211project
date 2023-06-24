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

int main(int argc, char* argv[]){
//    std::string fileName = argv[1];
    std::string fileName = "dataset1.txt";
    std::ifstream fileIn(fileName);

    // exception handling / checking if file is opening
    if (!fileIn.is_open()) {
        std::cerr << "Couldn't open the file: " << fileName << std::endl;
        return 1;
    }
    // store the three columns of the files' data
    std::vector<std::string> types;
    std::vector<std::string> names;
    std::vector<float> scores;
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
    for (std::size_t i = 0; i < (types.size()); i++){
        // checking to see if the file was stored correctly
        std::cout << types[i] << " " << names[i] << " " << scores[i] << "\n";
    }
    /*
     *
     *
     *
     * if file is open
     * take in the lines as such
     *
     * create three vectors to hold in the Type, Name, and Score
     *
     *
     *              // using space separation as default, cast the three items into vars
                    while (linestream >> type >> name >> score){
                        if (type != "Type" && name != "Name" && score != "Score" ){








    return 0;
}


