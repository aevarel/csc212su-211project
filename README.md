# csc212su-211project

## Project Requirements


## Requirements
An effective output will provide merely a course grade calculated based on all possible points that can be earned within the course.
Program
- [ ] Write a program to successfully evaluate individual deliverables from CSC 212 to provide an accurate output of semester course grades. Viewable outputs should include:
- [ ] individual: returns an individual deliverable name and grade
      - get deliverable object
            - return name, and grade
     some possible variables^^^
- [ ] category: returns all grades from the category and category total
     get category
      - probably a vector<deliverables> 
      - initialize a category of each type at runtime 
- [ ] course: ability to return each of the following:
  - all grades within their respective categories and a course overall
  - only category totals and course overall
  - only the course overall
  
  // since all the grades operate off of a point basis, we can set the 
- [ ] clear, conscientious comments embedded within the your code
- [ ] successfully compiles accurate output
- [ ] use read input to take in grades from an external file
- [ ] use write output to write any changes back to your input file

#### notes
  - this is a sample, let's just say the input just comes into this form since the professor says we can be flexible
  - if course points exceed category limits, ask user if there is bonus credit, but floor the final grade to 1000
  ```
  Type       Name          Score

  Lab        Lab_1         25
  Lab        Lab_2         20 
  Lab        Lab_3         0
  Lab        Lab_4         4
  Lab        Lab_5         25
  Lab        Lab_6         14
  Lab        Lab_7         25
  Lab        Lab_8         13
  Assignment Assignment_1  50
  Assignment Assignment_2  40
  Assignment Assignment_3  20
  Assignment Assignment_4  0
  Project1   Project_1     150
  Project2   Project_2     250
  Exam       Final_Exam    70
```

*** Exception handling ***
```
      - If Type != Lab || Assignment || Project || Exam
            - 'error, type of variable incorrect, please correct before continuing'
```
         - would essentially cover our bases for if the type is misspelled or entirely incorrect
      - If deliverable.Score > deliverable.ScoreMax // scoreMax is derived from the gradebook *or* category class, unsure which will be necessary at the present moment, but basically what the maximum amount of points a score can be without being extra credit
      // each deliverable should be constructed with a ScoreMax derived from categoryScoreMax[5]
            - 'warning, 'deliverable.Name' score exceeds deliverable.categoryType.ScoreMax, will be considered extra credit, check if intended'
            - 'here are the maximum scores per deliverable of the category types'
                  - assignment = 50 
                  - lab = 25
                  - project 1 = 150
                  - project 2 = 350
                  - final = 100

 #### Some hardcoded structures / variables
 - Maximum total score per category, maybe an int value MaxScore: ``` Score[Labs, Assignments, Projects, Final] = [200, 200, 500, 100] ```
      - If total score > Category->CourseTotal{ floor the CourseTotal score}
              - wouldnt do this for the individual assignment score since it would essentially nullify the impact of the extra credit
-  Student has
  
## Class Structure

#### Gradebook

#### Deliverable{
// object of an assignment
private:
      - grade // the grade of the assignments
      - 
public:


#### Category{
- [ ] category: returns all grades from the category and category total
     get category
      - probably a vector<deliverables> 
      - initialize a category of each type at runtime 
```
private:
categoryScores[Labs, Assignments, Projects, Final] = [200, 200, 500,100]
categoryScoreMaxes[25, 50, 150, 350, 100]
public:


```
- create a parameterized constructor
      - if type == labs, create
  }
}
  
private variables
      - vector<Category> gradeCategories // vector of the different course categories
      - vector<*deliverable> deliverableGradebook // vector of pointers to the actual deliverable objects we will create from the input.txt   

public:
            - gradeCategories()` default constructor:
            // basically we're pushing a bunch of pointers to the private 'Category' objects of different types 
            ```
            this->gradeCategories.push_back(*labs); this->gradeCategories.push_back(*assignments); this->gradeCategories.push_back(*projects); this->gradeCategories.push_back(*final_exam)
            ```



#### Deliverable
// object of an assignment
private:
      - grade // the grade of the assignments
      - 
public:


#### Student is a Gradebook (Student::Gradebook)

