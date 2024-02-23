//#include <QMap>

//private:
//    Ui::MainWindow *ui;
//    QMap <int, Student> students;

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>
#include "student.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAdd_clicked();
    void on_pushButton_clicked();

    std::vector<Student> compareStudentsBySalary(QString i);

private:
    Ui::MainWindow *ui;
    std::vector<Student> students;

    void updateTable(int index);
    void updateList();
};

#endif // MAINWINDOW_H
