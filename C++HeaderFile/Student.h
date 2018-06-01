#include <string>

using namespace std;

class Student {

    // constructor
    Student(string); 

    // setters
    void setId(string);
    void setDepartment(string);
    void setClassYear(string);
    void setFirstName(string);
    void setLastName(string);

    // getters
    string getId();
    string getDepartment();
    string getClassYear();
    string getFirstName();
    string getLastName();

    // utility 
    void displayStudentInfo();

};