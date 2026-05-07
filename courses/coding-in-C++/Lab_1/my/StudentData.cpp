#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

struct StudentData{
    std::string name;
    int homework_score = 0;
    int midterm_score = 0;
    int finalExame = 0;
    double finalGrade = 0.0;
    std::string letterGrade;
};

void readStudentData(StudentData &stud){

    std::cout << "\n\n\tWhats your name?:";
    getline(std::cin, stud.name);

    std::cout <<"\n\n\tHomework score:";
    std::cin >> stud.homework_score;
    
    std::cout <<"\n\n\tmidterm score:";
    std::cin >> stud.midterm_score;

    std::cout <<"\n\n\tfinalExame:";
    std::cin >> stud.finalExame;
};

void calculateGrades(StudentData &stud){
    stud.finalGrade = 0.4 * stud.homework_score + 0.25 * stud.midterm_score + 0.35 * stud.finalExame;
    
    if (stud.finalGrade >= 90)
    {
        stud.letterGrade = "A";
        return;
    }

    if (stud.finalGrade >= 80)
    {
        stud.letterGrade = "B";
        return;
    }

    if (stud.finalGrade >= 70)
    {
        stud.letterGrade = "C";
        return;
    }

    if (stud.finalGrade >= 60)
    {
        stud.letterGrade = "D";
        return;
    }

    if (stud.finalGrade >= 50)
    {
        stud.letterGrade = "E";
        return;
    }
    
    if (stud.finalGrade < 50)
    {
        stud.letterGrade = "F";
        return;
    }

};


void printReport(StudentData &stud){
    const int lineWidth = 30;
    const int labelWidth = 16;
    const std::string status = stud.finalGrade >= 50 ? "Pass" : "Fail";

    std::cout << std::fixed << std::setprecision(2) << std::left;
    std::cout << "\n\n";
    std::cout << std::setfill('-') << std::setw(lineWidth) << "" << '\n' << std::setfill(' ');
    std::cout << "Student Report" << '\n';
    std::cout << std::setfill('-') << std::setw(lineWidth) << "" << '\n' << std::setfill(' ');
    std::cout << "Name: " << stud.name << '\n';
    std::cout << '\n';
    std::cout << "Scores" << '\n';
    std::cout << std::setfill('-') << std::setw(lineWidth) << "" << '\n' << std::setfill(' ');
    std::cout << std::setw(labelWidth) << "Homework" << ": " << static_cast<double>(stud.homework_score) << '\n';
    std::cout << std::setw(labelWidth) << "Midterm" << ": " << static_cast<double>(stud.midterm_score) << '\n';
    std::cout << std::setw(labelWidth) << "Final Exam" << ": " << static_cast<double>(stud.finalExame) << '\n';
    std::cout << '\n';
    std::cout << std::setw(labelWidth) << "Final Grade" << ": " << stud.finalGrade << '\n';
    std::cout << std::setw(labelWidth) << "Letter Grade" << ": " << stud.letterGrade << '\n';
    std::cout << std::setw(labelWidth) << "Status" << ": " << status << '\n';
    std::cout << std::setfill('-') << std::setw(lineWidth) << "" << '\n';
    std::cout << std::setfill(' ');
}

int main (){

    StudentData student1;

    readStudentData(student1);
    calculateGrades(student1);
    printReport(student1);
    return 0;
}


