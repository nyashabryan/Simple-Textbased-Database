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

    struct StudentRecord{
        std::string Name;
        std::string Surname;
        std::string StudentNumber;
        std::string ClassRecord;
    };
}

#endif
