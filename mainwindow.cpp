#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->table->setColumnCount(2);
    QTableWidgetItem* item1 = new QTableWidgetItem("Имя Фамилия");
    QTableWidgetItem* item2 = new QTableWidgetItem("Зарплата");

    ui->table->setHorizontalHeaderItem(0, item1);
    ui->table->setHorizontalHeaderItem(1, item2);

    ui->table->horizontalHeader()->setDefaultSectionSize(100);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnAdd_clicked() {
    QString firstName = ui->textEditName->toPlainText();
    QString secondName = ui->textEditSecondName->toPlainText();
    int salary = ui->textEditSalary->toPlainText().toInt();
    Student newStudent(firstName, secondName, salary);
    students.push_back(newStudent);

    if(students.size() > 1) updateList();

    updateTable(0);
}

void MainWindow::updateTable(int index) {
    int size = students.size();

    ui->table->setColumnCount(2);

    QTableWidgetItem* item1 = new QTableWidgetItem("Имя Фамилия");
    QTableWidgetItem* item2 = new QTableWidgetItem("Зарплата");

    ui->table->setHorizontalHeaderItem(0, item1);
    ui->table->setHorizontalHeaderItem(1, item2);

    ui->table->setRowCount(size);

    int count = 0;

    if(index == 0) {
        for(auto st : students){
            QTableWidgetItem* nameItem = new QTableWidgetItem(st.getName());
            QTableWidgetItem* salaryItem = new QTableWidgetItem(QString::number(st.getSalary()));

            ui->table->setItem(count, 0, nameItem);
            ui->table->setItem(count++, 1, salaryItem);
        }
    }


    else if(index == 1) {
        students = compareStudentsBySalary(">");

        for(auto st : students){
            QTableWidgetItem* nameItem = new QTableWidgetItem(st.getName());
            QTableWidgetItem* salaryItem = new QTableWidgetItem(QString::number(st.getSalary()));

            ui->table->setItem(count, 0, nameItem);
            ui->table->setItem(count++, 1, salaryItem);
        }
    }


    else if(index == 2) {
        students = compareStudentsBySalary("<");

        for(auto st : students){
            QTableWidgetItem* nameItem = new QTableWidgetItem(st.getName());
            QTableWidgetItem* salaryItem = new QTableWidgetItem(QString::number(st.getSalary()));

            ui->table->setItem(count, 0, nameItem);
            ui->table->setItem(count++, 1, salaryItem);
        }
    }

    ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);  // Не дает менять данные в таблице
}

void MainWindow::updateList(){
    ui->sortedType->addItem("По возрастанию");
    ui->sortedType->addItem("По убыванию");
}

std::vector<Student> MainWindow::compareStudentsBySalary(QString i) {
    int buf1[students.size()];
    for(int i=0;i<students.size(); i++){
        buf1[i] = students[i].getSalary();
    }

    int n = students.size();
    bool swapped;

    if (i == ">"){
        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (buf1[j] < buf1[j + 1]) {
                    std::swap(buf1[j], buf1[j + 1]);
                    swapped = true;
                }
            }
            // Если на данной итерации не было ни одного обмена, значит массив уже отсортирован
            if (!swapped) {
                break;
            }
        }
    }

    else{
        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (buf1[j] > buf1[j + 1]) {
                    std::swap(buf1[j], buf1[j + 1]);
                    swapped = true;
                }
            }
            // Если на данной итерации не было ни одного обмена, значит массив уже отсортирован
            if (!swapped) {
                break;
            }
        }
    }

    std::vector<Student> buf2;

    for(int i=0; i<students.size(); i++){
        for(int j=0; j < students.size(); j++){
            if(buf1[i] == students[j].getSalary()){
                buf2.push_back(students[j]);
            }
        }
    }
    return buf2;
}

void MainWindow::on_pushButton_clicked() {
    QString select = ui->sortedType->currentText();
    if (select == "По возрастанию"){
        updateTable(1);
    }
    else{
        updateTable(2);
    }
}
