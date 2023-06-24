#include <vector>
#include <string>


class Gradebook {

private:
    std::string fileName;

public:
    // parameterized constructor for Gradebook object is default
    Gradebook(std::string fileName);

    // setter for fileName
    void setfileName();
    // getter for fileName
    void getfileName();


    friend class Deliverable;
};

class Deliverable{
// object of an assignment private: - string name
// name of assignment - int grade
// grade of the assignment - int max_grade
// max points of assignment public: Deliverable();
// default constructor

private:
    // Reference: 0 = Labs deliverable, Assignments = 1, Projects = 2, Exam = 3

    // could make the first column of the input be an index, make categoryScores[1stColumn#] assign the name as its type
    std::string categoryTypes[4] = {"Labs", "Assignments", "Projects", "Exam"};
    int categoryTypeIndex;
    std::string name;
    int grade;

public:
    Deliverable(std::string name, int grade, int category) //overloaded constructor
    {
        this->categoryTypeIndex = category;
        this->name = name;
        this->grade = grade;
    }
    std::string getName(){
        return this->name;
    }
    int getGrade(){
        return this->grade;
    }
    void setGrade(int grade){
    }
    void setName(std::string name){

    }

};


// return total grade for section pseudocode
// Reference Indexes: 0 = Labs deliverable, Assignments = 1, Projects = 2, Exam = 3
                // present the user with the options as referenced above
    // float int sectionTotalGrade(int categoryIndex){
        // iterate through vector of pointers to deliverables in gradebook object
        //


