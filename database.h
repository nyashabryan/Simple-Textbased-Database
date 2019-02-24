#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "database.h"

using namespace std;

namespace KTMNYA001 {

    struct StudentRecord{
        std::string Name;
        std::string Surname;
        std::string StudentNumber;
        std::string ClassRecord;
    };

    void add_student(std::vector<StudentRecord> database);

    void read_database(
        std::vector<StudentRecord> database
    );

    void save_database(
        std::vector<StudentRecord> database
    );

    void display_student(
        std::vector<StudentRecord> database,
        std::string student_number
    );

    float grade_student(
        std::vector<StudentRecord> database,
        std::string student_number
    );
}

#endif
