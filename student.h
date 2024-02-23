#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student {
private:
    int salary;
    QString firstName;
    QString secondName;
    int UniqId = 0;
    static int id;
public:
    Student();
    Student(const QString firstName, const QString secondName, const int salary);

    QString getName() const;
    int getSalary() const;
    int getId() const;
};

#endif // STUDENT_H
