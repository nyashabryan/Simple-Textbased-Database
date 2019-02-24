#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

using namespace std;
namespace KTMNYA001 {
    void add_student(
        std::string name,
        std::string surname,
        std::string student_number,
        std::string class_record,
        std::vector<StudentRecord> database
        );

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

    struct StudentRecord{
        std::string Name;
        std::string Surname;
        std::string StudentNumber;
        std::string ClassRecord;
    };
}

#endif
