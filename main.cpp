// Simple Textbased Student Database

#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <algorithm>
#include <cstdlib>
#include "database.h"

using namespace std;
using namespace KTMNYA001;

int main()
{
    system("clear");
    vector<StudentRecord> database;

    vector<string> mainQuery;
    mainQuery.push_back("0: Add student");
    mainQuery.push_back("1: Read database");
    mainQuery.push_back("2: Save database");
    mainQuery.push_back("3: Display given student data");
    mainQuery.push_back("4: Grade student");
    mainQuery.push_back("q: Quit");
    mainQuery.push_back("Enter a number (or q to quit) and press return...");

    string choice;
    // loop forever
    for (;;){
        for(int i = 0; i < mainQuery.size(); i++)
            cout << mainQuery[i] << "\n";

        cin >> choice;
        system("clear");
        if (choice == "q"){
            cout << "Exiting the database application" << std::endl;
            break;

        }else if(choice == "0"){
            
            cout << "Selected addStudent function" << std::endl;
            database = add_student(database);
            system("clear");
            // Alert student has been added to database
            cout << "Student has been successfully added to database\n";

        }else if(choice == "1"){
            cout << "Selected readDatabase function" << std::endl;
            database = read_database(database);
            system("clear");
            // Alert database has been loaded
            cout << "Database has been loaded\n";

        }else if(choice == "2"){
            cout << "Selected saveDatabase function" << std::endl;
            save_database(database);
            system("clear");
            // Alert database has been saved.
            cout << "Database has been saved.\n";

        }else if(choice == "3"){
            cout << "Selected queryStudent function" << std::endl;
            display_student(database);

        }else if(choice == "4"){
            cout << "Selected gradeStudent function" << std::endl;
            grade_student(database);

        }else{
            cerr << "Invalid Choice. Please choose another.\n";
        }
    
    }
    return 0;
}