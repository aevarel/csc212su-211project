#include <vector>
#include <string>

class Deliverable{
// object of an assignment private: - string name
// name of assignment - int grade
// grade of the assignment - int max_grade
// max points of assignment public: Deliverable();
// default constructor

private:
    std::string name, category;
    float grade;

public:
    int categoryScoreMax;
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
    this->grade = grade;
    }
    void setName(std::string name){
    this->name = name;
    }
};

class Gradebook {
private:
    std::string fileName;
    std::vector<std::string> masterStorageBuffer;

public:
    std::vector<Deliverable*> gradebookPtrs;

    explicit Gradebook(std::string fileName);

    void setfileName(const std::string& name);
    std::string getfileName();
    bool isValidType(const std::string& typeInput);
    bool isValidScore(const std::string& scoreInput);
    void generateGradebookPtrs(const std::vector<std::string> &types, const std::vector<std::string> &names, const std::vector<float> &scores);
    void printGradebookSelection(std::vector<Deliverable *> gradebookPtrs);
    std::vector<Deliverable *> searchGradebookType(std::string type);
    std::vector<Deliverable *> searchGradebookName(std::string name);
    float getCategoryMax(std::string category);
    int sumPoints(std::vector<Deliverable *> gradebookPtrs);
    float calculatePercentScore(int points, std::string category);

    friend class Deliverable;
};