#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <string>
#include "database.h"

using namespace KTMNYA001;
vector<StudentRecord> KTMNYA001::add_student(std::vector<StudentRecord> database){

    struct StudentRecord student;

    std::string data;
    std::cout << "Enter the student number: "<< std::endl;
    std::cin >> data;
    // conversion to lower case
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    student.StudentNumber = data;

    string value;
    std::getline(std::cin, value);

    // Check if student already exist in database
    for (int i = 0; i < database.size(); i++){
        
        if (database[i].StudentNumber == student.StudentNumber){
            
            std::cout << "Student already exists. Student information being changed." << std::endl;

            std::cout << "Enter the student name: " << std::endl;
            std::getline(std::cin, value);
            database[i].Name = value;

            std::cout << "Enter the student surname: " << std::endl;
            std::getline(std::cin, value);
            database[i].Surname = value;

            std::cout << "Enter the student class record: " << std::endl;
            std::getline(std::cin, value);
            database[i].ClassRecord = value;

            return database;
        }   
    }

    std::cout << "Enter the student name: " << std::endl;
    std::getline(std::cin, student.Name);

    std::cout << "Enter the student surname: " << std::endl;
    std::getline(std::cin, student.Surname);

    std::cout << "Enter the student class record: " << std::endl;
    std::getline(std::cin, student.ClassRecord);

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

        // Load the stude class record
        token = line.substr(0, line.find(delimiter));
        student.ClassRecord = token;

        database.push_back(student);
    }

    ifs.close();

    return database;
}

void KTMNYA001::display_student(std::vector<StudentRecord> database){
    // Ask the user for student number
    std::cout << "Please enter the student number: \n";

    // take in the student number
    string data;
    std::cin >> data;
    // transform to lower case
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
    string student_number = data;

    // Clear screen
    system("clear");

    // search for student number in database
    for (int i = 0; i < database.size(); i++){
        if (database[i].StudentNumber == student_number){
            std::cout << "Student found" << std::endl;
            std::cout << "Name: " << database[i].Name << std::endl;
            std::cout << "Surname: " << database[i].Surname << std::endl;
            std::cout << "Student Number: " << database[i].StudentNumber << std::endl;
            std::cout << "Class Record: " << database[i].ClassRecord << std::endl;
            std::cout << "\n";
            return ;
        }
    }

    std::cerr << "Student was not found\n\n";
}


void KTMNYA001::grade_student(vector<StudentRecord> database){
    // Ask for student number

    std::cout << "Enter student number for grading: " << std::endl;

    string student_number;
    string data;
    StudentRecord student;

    std::cin >> data;
    // Transform data to lower case.
    std::transform(data.begin(), data.end(), data.begin(), ::towlower);
    student_number = data;
    // Clear screen
    system("clear");

    // Initialize value

    float total;

    int value;
    int count = 0;

    // Loop through to find student
    for (int i = 0; i < database.size(); i++){

        if (database[i].StudentNumber == student_number){

            istringstream iss(database[i].ClassRecord);
            while (!iss.eof()){
                count++;
                iss >> value;
                total += (int)value;
            }
            
            float average = total / count;

            std::cout << "The student grade is: " << average << std::endl;

            return ;
        }
    }

    // Failed to find student
    std::cerr << "Failed to find the specified student" << std::endl;
}