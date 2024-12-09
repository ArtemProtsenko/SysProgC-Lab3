#pragma once

#include <iostream>
#include "Employee.h"
#include "Policy.h"
#include <vector>

namespace Records {
	const int kMaxEmployees = 100;
	const int kFirstEmployeeNumber = 1000;
	const int kMaxPolicies = 1000;
	const int kFirstPolicyNumber = 0;
	const int kFirstClientNumber = 0;
	class Database
	{
	public:
		Database();
		~Database();
		Employee& addEmployee(std::string inFirstName, std::string inLastName);
        Employee& readEmployee(std::string inFirstName, std::string inLastName, int employeeNumber, int salary, bool hired);
		Employee& getEmployee(int inEmployeeNumber);
        Employee& getEmployee(std::string inFirstName, std::string inLastName);
        std::vector<Employee> getAllEmployees() const;
		
		Policy& addPolicy(std::string inStartingDate, std::string endingDate, float inCost, int inTypeId, int inEmployeeId);
        Policy& readPolicy(int policyId, std::string startDate, std::string endDate, int cost, int payout, int typeId, int clientId, int employeeId, bool paid, bool expired);
		Policy& getPolicy(int inPolicyNumber);
        std::vector<Policy> getAllPolicies() const;
		void displayAllPolicies();
		void displayPaidPolicies();
		void displayNotPaidPolicies();
		void displayExpiredPolicies();
		void displayNotExpiredPolicies();
	protected:
		Employee mEmployees[kMaxEmployees];
		int mNextEmployeeSlot;
		int mNextEmployeeNumber;

		Policy mPolicies[kMaxPolicies];
		int mNextPolicySlot;
		int mNextPolicyNumber;
		int mNextClientSlot;
		int mNextClientNumber;
	};
}
