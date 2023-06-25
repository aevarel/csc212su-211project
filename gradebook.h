#include <vector>
#include <string>


class Gradebook {

    class Deliverable{
// object of an assignment private: - string name
// name of assignment - int grade
// grade of the assignment - int max_grade
// max points of assignment public: Deliverable();
// default constructor

    private:
        // Reference: 0 = Labs deliverable, Assignments = 1, Projects = 2, Exam = 3

        // could make the first column of the input be an index, make categoryScores[1stColumn#] assign the name as its type
        std::string name, category;
        float grade;

    public:
        Deliverable(const std::string& name, const std::string& category, float grade) //overloaded constructor
        {
            this->category = category;
            this->name = name;
            // this will be the points of the grade
            this->grade = grade;
        }
        std::string getName(){
            return this->name;
        }
        int getGrade(){
            return this->grade;
        }
        std::string getCategory(){
            return this->category;
        }
        void setGrade(int grade){
        }
        void setName(std::string name){

        }

    };

private:
    std::string fileName;
    std::vector<std::string> masterStorageBuffer;

public:
    std::vector<Deliverable>;
    // parameterized constructor for Gradebook object is default
    explicit Gradebook(std::string fileName);

    // variable handling methods
    // setter for fileName
    void setfileName(const std::string& name);
    // getter for fileName
    std::string getfileName();

    // file handling methods
    bool isValidType(const std::string& typeInput);
    bool isValidScore(const std::string& scoreInput);

    // main menu / functions responsible for the manipulation

        // define friendclass

};



// return total grade for section pseudocode
// Reference Indexes: 0 = Labs deliverable, Assignments = 1, Projects = 2, Exam = 3
                // present the user with the options as referenced above
    // float int sectionTotalGrade(int categoryIndex){
        // iterate through vector of pointers to deliverables in gradebook object
        //


