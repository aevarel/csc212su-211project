//
// Created by frabky on 6/25/2023.
//
#include "Deliverable.h"
using namespace std;
#include <string>

class Deliverable {
private:
    string type; //could be any of [Labs, Assignments, Project1, Project2, Exam]
    string name;  //derived from input file
    int grade; //grade of deliverable
    int maxPoints; //could be any of  [25, 50, 150, 350, 100]
public:
// parameterized constructor
    Deliverable(string type, string name, int grade, int maxPoints){
        this->type = type;
        this->name = name;
        this->grade = grade;
        this->maxPoints = maxPoints;
    }

    const string &getType() const {
        return type;
    }

    const string &getName() const {
        return name;
    }

    int getGrade() const {
        return grade;
    }

    int getMaxPoints() const {
        return maxPoints;
    }

    void setType(const string &type) {
        Deliverable::type = type;
    }

    void setName(const string &name) {
        Deliverable::name = name;
    }

    void setGrade(int grade) {
        Deliverable::grade = grade;
    }

    void setMaxPoints(int maxPoints) {
        Deliverable::maxPoints = maxPoints;
    }

};