#include <fstream>
#include <iostream>
#include "database.h"

using namespace KTMNYA001;
vector<StudentRecord> KTMNYA001::add_student(std::vector<StudentRecord> database){

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

        return database;
    }

void KTMNYA001::save_database(
    std::vector<StudentRecord> database){
    
    // Instantiate student
    struct StudentRecord student;

    // Instantiate filestream
    ofstream ofs("database.txt");
    // iterate through the vector
    std::cout << database.size();

    for (int i = 0; i < database.size(); i++){
        student = database[i];
        ofs << student.Name << ";";
        ofs << student.Surname << ";";
        ofs << student.StudentNumber << ";";
        ofs << student.ClassRecord << ";";
        ofs << "\n";
    }

    ofs.close();
}

std::vector<StudentRecord> KTMNYA001::read_database(std::vector<StudentRecord> database){

    // Instantiate student
    struct StudentRecord student;

    // Instantiate filestream
    ifstream ifs("database.txt");

    // Instantiate string line
    string line;

    // instantiate delimiter
    string delimiter = ";";

    // Instantiate token
    string token;

    while (getline(ifs, line)){
        // Process line into student.

        // Load the student name
        token = line.substr(0, line.find(delimiter));
        student.Name = token;
        line.erase(0, line.find(delimiter) + delimiter.size());

        // Load the student surname
        token = line.substr(0, line.find(delimiter));
        student.Surname = token;
        line.erase(0, line.find(delimiter) + delimiter.size());

        // Load the student number
        token = line.substr(0, line.find(delimiter));
        student.StudentNumber = token;
        line.erase(0, line.find(delimiter) + delimiter.size());

        database.push_back(student);
    }

    ifs.close();

    std::cout << "Database loaded successfully.";
}
