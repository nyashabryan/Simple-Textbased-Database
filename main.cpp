// Simple Textbased Student Database

#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include "database.h"

using namespace std;
using namespace KTMNYA001;

int main()
{
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
            break;

        }else if(choice == "0"){

            database = add_student(database);

        }else if(choice == "1"){

            database = read_database(database);

        }else if(choice == "2"){

            save_database(database);

        }else if(choice == "3"){

        }else if(choice == "4"){

        }else{
            cout << "Invalid Choice. Please choose another.\n";
        }
    
    }
    return 0;
}