// Simple Textbased Student Database

#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <cstdlib>

using namespace std;

int main()
{
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
        }
    
    }
    return 0;
}