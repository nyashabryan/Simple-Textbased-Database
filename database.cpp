#include <fstream>
#include <iostream>
#include "database.h"

using namespace KTMNYA001;
void KTMNYA001::add_student(std::vector<StudentRecord> database){

        struct StudentRecord student;

        std::cout << "Enter the student name: \n";
        std::cin >> student.Name;

        std::cout << "Enter the student surname: \n";
        std::cin >> student.Surname;

        std::cout << "Enter the student number: \n";
        std::cin >> student.StudentNumber;

        std::cout << "Enter the student class record: \n";
        std::cin >> student.ClassRecord;

        // put the student into the database
        database.push_back(student);

        // confirm student saved.
        std::cout << "Student saved successfully\n";
    }

void KTMNYA001::save_database(
    std::vector<StudentRecord> database){
    
    // Instantiate student
    StudentRecord student;

    // Instantiate filestream
    ofstream ofs("database.txt");
    // iterate through the vector
    for (int i = 0; i < database.size(); i++){
        student = database[i];
        ofs << student.Name << ";";
        ofs << student.Surname << ";";
        ofs << student.StudentNumber << ";";
        ofs << student.ClassRecord << ";";
        ofs << "\n";
    }

    ofs.close();
    std::cout << "Database has been saved\n";
}

