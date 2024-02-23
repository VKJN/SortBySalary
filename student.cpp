#include "student.h"

int Student::id = 0;

Student::Student(){}

Student::Student(const QString firstName, const QString secondName, const int salary) {
    this->firstName = firstName;
    this->secondName = secondName;
    this->salary = salary;
    UniqId = ++id;
}

QString Student::getName() const {
    return firstName + " " + secondName;
}

int Student::getSalary() const {
    return salary;
}

int Student::getId() const {
    return UniqId;
}
