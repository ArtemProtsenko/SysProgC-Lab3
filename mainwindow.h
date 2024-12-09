#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Database.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void hireEmployee();
    void fireEmployee();
    void promoteEmployee();
    void demoteEmployee();
    void listAllEmployees();
    void listCurrentEmployees();
    void listFormerEmployees();
    void makePolicy();
    void payoutPolicy();
    void markPolicyExpired();
    void listAllPolicies();
    void listPaidPolicies();
    void listNotPaidPolicies();
    void listExpiredPolicies();
    void listNotExpiredPolicies();
    void writeEmployeesToFile();
    void writePoliciesToFile();
    void readEmployeesFromFile();
    /*void readPoliciesFromFile();*/

private:
    Records::Database m_database;
    void setupUi();
};

#endif // MAINWINDOW_H
