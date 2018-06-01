#include <iostream>
#include "Student.h"
using namespace std;

// constructor

void Student::Student(string studentId) {
    setId(studentId);
}

// setters

void Student::setId(string studentId) {
    id = studentId;
}

void Student::setFirstName(string fname) {
    firstName = fname;
}

void Student::setLastName(string lname) {
    lastName = lname;
}

void Student::setDepartment(string dep) {
    department = dep;
}

void Student::setClassYear(string year) {
    classYear = year;
}

// getters

string Student::getId() {
    return id;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getDepartment() {
    return department;
}

string Student::getClassYear() {
    return classYear;
}

// utility function

void Student::displayStudentInfo() {
    cout<<"Student Id: "<<getId()<<endl;
    cout<<"Full name: "<<getFirstName()<<" "<<getLastName()<<endl;
    cout<<"Department: "<<getDepartment()<<endl;
    cout<<"Class Year: "<<getClassYear()<<endl;
}

