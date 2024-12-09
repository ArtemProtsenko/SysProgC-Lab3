#include "MainWindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QList>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setupUi();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
    setWindowTitle("Employee and Policy Database");
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QPushButton *hireButton = new QPushButton("Hire a new employee", this);
    connect(hireButton, &QPushButton::clicked, this, &MainWindow::hireEmployee);
    layout->addWidget(hireButton);

    QPushButton *fireButton = new QPushButton("Fire an employee", this);
    connect(fireButton, &QPushButton::clicked, this, &MainWindow::fireEmployee);
    layout->addWidget(fireButton);

    QPushButton *promoteButton = new QPushButton("Promote an employee", this);
    connect(promoteButton, &QPushButton::clicked, this, &MainWindow::promoteEmployee);
    layout->addWidget(promoteButton);

    QPushButton *demoteButton = new QPushButton("Demote an employee", this);
    connect(demoteButton, &QPushButton::clicked, this, &MainWindow::demoteEmployee);
    layout->addWidget(demoteButton);

    QPushButton *listAllEmpButton = new QPushButton("List all employees", this);
    connect(listAllEmpButton, &QPushButton::clicked, this, &MainWindow::listAllEmployees);
    layout->addWidget(listAllEmpButton);

    QPushButton *listCurrentEmpButton = new QPushButton("List current employees", this);
    connect(listCurrentEmpButton, &QPushButton::clicked, this, &MainWindow::listCurrentEmployees);
    layout->addWidget(listCurrentEmpButton);

    QPushButton *listFormerEmpButton = new QPushButton("List former employees", this);
    connect(listFormerEmpButton, &QPushButton::clicked, this, &MainWindow::listFormerEmployees);
    layout->addWidget(listFormerEmpButton);

    QPushButton *makePolicyButton = new QPushButton("Make a policy", this);
    connect(makePolicyButton, &QPushButton::clicked, this, &MainWindow::makePolicy);
    layout->addWidget(makePolicyButton);

    QPushButton *payoutButton = new QPushButton("Payout policy", this);
    connect(payoutButton, &QPushButton::clicked, this, &MainWindow::payoutPolicy);
    layout->addWidget(payoutButton);

    QPushButton *markExpiredButton = new QPushButton("Mark policy as expired", this);
    connect(markExpiredButton, &QPushButton::clicked, this, &MainWindow::markPolicyExpired);
    layout->addWidget(markExpiredButton);

    QPushButton *listAllPoliciesButton = new QPushButton("List all policies", this);
    connect(listAllPoliciesButton, &QPushButton::clicked, this, &MainWindow::listAllPolicies);
    layout->addWidget(listAllPoliciesButton);

    QPushButton *listPaidPoliciesButton = new QPushButton("List paid policies", this);
    connect(listPaidPoliciesButton, &QPushButton::clicked, this, &MainWindow::listPaidPolicies);
    layout->addWidget(listPaidPoliciesButton);

    QPushButton *listNotPaidPoliciesButton = new QPushButton("List not paid policies", this);
    connect(listNotPaidPoliciesButton, &QPushButton::clicked, this, &MainWindow::listNotPaidPolicies);
    layout->addWidget(listNotPaidPoliciesButton);

    QPushButton *listExpiredPoliciesButton = new QPushButton("List expired policies", this);
    connect(listExpiredPoliciesButton, &QPushButton::clicked, this, &MainWindow::listExpiredPolicies);
    layout->addWidget(listExpiredPoliciesButton);

    QPushButton *listNotExpiredPoliciesButton = new QPushButton("List not expired policies", this);
    connect(listNotExpiredPoliciesButton, &QPushButton::clicked, this, &MainWindow::listNotExpiredPolicies);
    layout->addWidget(listNotExpiredPoliciesButton);

    QPushButton *writeEmployeesToFile = new QPushButton("Write employees to file", this);
    connect(writeEmployeesToFile, &QPushButton::clicked, this, &MainWindow::writeEmployeesToFile);
    layout->addWidget(writeEmployeesToFile);

    QPushButton *readEmployeesFromFile = new QPushButton("Read employees from file", this);
    connect(readEmployeesFromFile, &QPushButton::clicked, this, &MainWindow::readEmployeesFromFile);
    layout->addWidget(readEmployeesFromFile);

    QPushButton *writePoliciesToFile = new QPushButton("Write policies to file", this);
    connect(writePoliciesToFile, &QPushButton::clicked, this, &MainWindow::writePoliciesToFile);
    layout->addWidget(writePoliciesToFile);

    /*QPushButton *readPoliciesFromFile = new QPushButton("Read policies from file", this);
    connect(readPoliciesFromFile, &QPushButton::clicked, this, &MainWindow::readPoliciesFromFile);
    layout->addWidget(readPoliciesFromFile);*/

    setCentralWidget(centralWidget);
}

void MainWindow::hireEmployee() {
    bool ok;
    QString firstName = QInputDialog::getText(this, "Hire Employee", "First Name:", QLineEdit::Normal, "", &ok);
    if (!ok || firstName.isEmpty()) return;

    QString lastName = QInputDialog::getText(this, "Hire Employee", "Last Name:", QLineEdit::Normal, "", &ok);
    if (!ok || lastName.isEmpty()) return;

    try {
        m_database.addEmployee(firstName.toStdString(), lastName.toStdString());
        QMessageBox::information(this, "Success", "Employee hired successfully!");
    } catch (...) {
        QMessageBox::critical(this, "Error", "Unable to hire employee.");
    }
}

void MainWindow::fireEmployee() {
    bool ok;
    QString employeeId = QInputDialog::getText(this, "Fire Employee", "Id:", QLineEdit::Normal, "", &ok);
    if (!ok || employeeId.isEmpty()) return;

    try {
        m_database.getEmployee(employeeId.toInt()).fire();
        QMessageBox::information(this, "Success", "Employee fired successfully!");
    } catch (...) {
        QMessageBox::critical(this, "Error", "Unable to fire employee.");
    }
}

void MainWindow::promoteEmployee() {
    bool ok;
    QString employeeId = QInputDialog::getText(this, "Promote Employee", "Id:", QLineEdit::Normal, "", &ok);
    if (!ok || employeeId.isEmpty()) return;

    QString amount = QInputDialog::getText(this, "Promote Employee", "Amount:", QLineEdit::Normal, "", &ok);
    if (!ok || amount.isEmpty()) return;

    try {
        m_database.getEmployee(employeeId.toInt()).promote(amount.toInt());
        QMessageBox::information(this, "Success", "Employee promoted successfully!");
    } catch (...) {
        QMessageBox::critical(this, "Error", "Unable to promote employee.");
    }
}

void MainWindow::demoteEmployee() {
    bool ok;
    QString employeeId = QInputDialog::getText(this, "Demote Employee", "Id:", QLineEdit::Normal, "", &ok);
    if (!ok || employeeId.isEmpty()) return;

    QString amount = QInputDialog::getText(this, "Demote Employee", "Amount:", QLineEdit::Normal, "", &ok);
    if (!ok || amount.isEmpty()) return;

    try {
        m_database.getEmployee(employeeId.toInt()).demote(amount.toInt());
        QMessageBox::information(this, "Success", "Employee demoted successfully!");
    } catch (...) {
        QMessageBox::critical(this, "Error", "Unable to demote employee.");
    }
}

void MainWindow::listAllEmployees() {
    QString employeeList;
    auto employees = m_database.getAllEmployees();
    for (auto& emp : employees) {
        employeeList += QString::fromStdString(emp.getInfo()) + "\n";
    }
    QMessageBox::information(this, "Employee List", employeeList);
}

void MainWindow::listCurrentEmployees() {
    QString employeeList;
    auto employees = m_database.getAllEmployees();
    for (auto& emp : employees) {
        if (emp.getIsHired()) {
            employeeList += QString::fromStdString(emp.getInfo()) + "\n";
        }
    }
    QMessageBox::information(this, "Current employee List", employeeList);
}

void MainWindow::listFormerEmployees() {
    QString employeeList;
    auto employees = m_database.getAllEmployees();
    for (auto& emp : employees) {
        if (!emp.getIsHired()) {
            employeeList += QString::fromStdString(emp.getInfo()) + "\n";
        }
    }
    QMessageBox::information(this, "Former employee List", employeeList);
}

void MainWindow::makePolicy() {
    bool ok;
    QString startDate = QInputDialog::getText(this, "Make Policy", "Start Date:", QLineEdit::Normal, "", &ok);
    if (!ok || startDate.isEmpty()) return;

    QString endDate = QInputDialog::getText(this, "Make Policy", "End Date:", QLineEdit::Normal, "", &ok);
    if (!ok || endDate.isEmpty()) return;

    float cost = QInputDialog::getDouble(this, "Make Policy", "Cost:", 0, 0, 1000000, 2, &ok);
    if (!ok) return;

    int employeeNumber = QInputDialog::getInt(this, "Make Policy", "Employee Number:", 0, 0, 10000, 1, &ok);
    if (!ok) return;

    try {
        m_database.addPolicy(startDate.toStdString(), endDate.toStdString(), cost, 1, employeeNumber);
        QMessageBox::information(this, "Success", "Policy created successfully!");
    } catch (...) {
        QMessageBox::critical(this, "Error", "Unable to create policy.");
    }
}

void MainWindow::payoutPolicy() {
    bool ok;
    QString policyId = QInputDialog::getText(this, "Payout policy", "Id:", QLineEdit::Normal, "", &ok);
    if (!ok || policyId.isEmpty()) return;

    QString amount = QInputDialog::getText(this, "Payout policy", "Amount:", QLineEdit::Normal, "", &ok);
    if (!ok || amount.isEmpty()) return;

    try {
        m_database.getPolicy(policyId.toInt()).setPayout(amount.toFloat());
        m_database.getPolicy(policyId.toInt()).markAsPaid();
        QMessageBox::information(this, "Success", "Payout successful!");
    } catch (...) {
        QMessageBox::critical(this, "Error", "Unable to payout policy.");
    }
}

void MainWindow::markPolicyExpired() {
    bool ok;
    QString policyId = QInputDialog::getText(this, "Payout policy", "Id:", QLineEdit::Normal, "", &ok);
    if (!ok || policyId.isEmpty()) return;

    try {
        m_database.getPolicy(policyId.toInt()).markAsExpired();
        QMessageBox::information(this, "Success", "Marked as expired successful!");
    } catch (...) {
        QMessageBox::critical(this, "Error", "Unable to mark policy as expired.");
    }
}

void MainWindow::listAllPolicies() {
    QString policyList;
    auto policies = m_database.getAllPolicies();
    for (auto& policy : policies) {
        policyList += QString::fromStdString(policy.getInfo()) + "\n";
    }
    QMessageBox::information(this, "Policies List", policyList);
}

void MainWindow::listPaidPolicies() {
    QString policyList;
    auto policies = m_database.getAllPolicies();
    for (auto& policy : policies) {
        if (policy.getIsPaid()) {
            policyList += QString::fromStdString(policy.getInfo()) + "\n";
        }
    }
    QMessageBox::information(this, "Paid Policies List", policyList);
}

void MainWindow::listNotPaidPolicies() {
    QString policyList;
    auto policies = m_database.getAllPolicies();
    for (auto& policy : policies) {
        if (!policy.getIsPaid()) {
            policyList += QString::fromStdString(policy.getInfo()) + "\n";
        }
    }
    QMessageBox::information(this, "Not Paid Policies List", policyList);
}

void MainWindow::listExpiredPolicies() {
    QString policyList;
    auto policies = m_database.getAllPolicies();
    for (auto& policy : policies) {
        if (policy.getIsExpired()) {
            policyList += QString::fromStdString(policy.getInfo()) + "\n";
        }
    }
    QMessageBox::information(this, "Expired Policies List", policyList);
}

void MainWindow::listNotExpiredPolicies() {
    QString policyList;
    auto policies = m_database.getAllPolicies();
    for (auto& policy : policies) {
        if (!policy.getIsExpired()) {
            policyList += QString::fromStdString(policy.getInfo()) + "\n";
        }
    }
    QMessageBox::information(this, "Not Expired Policies List", policyList);
}

void MainWindow::writeEmployeesToFile() {
    QFile file("employees.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qCritical() << "Unable to open employee file for writing!";
        return;
    }

    QTextStream out(&file);

    QString employeeList;
    auto employees = m_database.getAllEmployees();
    for (auto& employee : employees) {
        out << QString::fromStdString(employee.getFirstName()) << ", "
            << QString::fromStdString(employee.getLastName()) << ", "
            << employee.getEmployeeNumber() << ", "
            << QString::fromStdString(std::to_string(employee.getSalary())) << ", "
            << (employee.getIsHired() ? 1 : 0) << "\n";
    }

    file.close();
}

void MainWindow::readEmployeesFromFile() {
    QFile file("employees.txt");

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(", ");
        std::string firstName = parts[0].toStdString();
        std::string lastName = parts[1].toStdString();
        int employeeNumber = parts[2].toInt();
        int salary = parts[3].toInt();
        int hiredInt = parts[4].toInt();
        bool hired = (hiredInt == 1 ? true : false);

        std::cout << firstName;

        m_database.readEmployee(firstName, lastName, employeeNumber, salary, hired);
    }

    file.close();
}

void MainWindow::writePoliciesToFile() {
    QFile file("policies.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qCritical() << "Unable to open policy file for writing!";
        return;
    }

    QTextStream out(&file);

    QString policiesList;
    auto policies = m_database.getAllPolicies();

    for (auto& policy : policies)
    {
        out << policy.getPolicyNumber() << ", "
            << QString::fromStdString(policy.getStartingDate()) << ", "
            << QString::fromStdString(policy.getEndingDate()) << ", "
            << policy.getCost() << ", "
            << policy.getPayout() << ", "
            << policy.getPolicyTypeId() << ", "
            << policy.getClientId() << ", "
            << policy.getEmployeeId() << ", "
            << (policy.getIsPaid() ? 1 : 0)
            << (policy.getIsExpired() ? 1 : 0) << "\n";
    }

    file.close();
}

/*void MainWindow::readPoliciesFromFile() {
    QFile file("policies.txt");

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(", ");
        int policyNumber = parts[0].toInt();
        std::string startDate = parts[1].toStdString();
        std::string endDate = parts[2].toStdString();
        int cost = parts[3].toInt();
        int payout = parts[4].toInt();
        int policyTypeId = parts[5].toInt();
        int clientId = parts[6].toInt();
        int employeeId = parts[7].toInt();
        int paidInt = parts[8].toInt();
        int expiredInt = parts[9].toInt();
        bool paid = (paidInt == 1 ? true : false);
        bool expired = (expiredInt == 1 ? true : false);

        m_database.readPolicy(policyNumber, startDate, endDate, cost, payout, policyTypeId, clientId, employeeId, paid, expired);
    }

    file.close();
}
*/
