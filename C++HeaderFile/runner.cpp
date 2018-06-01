#include <iostream>
#include <Student.h>
using namespace std;

int main() {

    Student student("ATR/2100/08");
    student.setFirstName("Elias");
    student.setLastName("Addisu");
    student.setDepartment("Software Engineering");
    student.setClassYear("Junior");

    student.displayStudentInfo();

}
