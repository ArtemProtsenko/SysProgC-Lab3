#include <iostream>
#include <stdexcept>
#include <string>
#include "Database.h"
#include <vector>

using namespace std;

namespace Records {
	Database::Database()
	{
		mNextEmployeeSlot = 0;
		mNextEmployeeNumber = kFirstEmployeeNumber;

		mNextPolicySlot = 0;
		mNextPolicyNumber = kFirstPolicyNumber;
		mNextClientSlot = 0;
		mNextClientNumber = kFirstClientNumber;
	}
	Database::~Database()
	{
    }
    Employee& Database::addEmployee(string inFirstName, string inLastName)
    {
        if (mNextEmployeeSlot >= kMaxEmployees) {
            cerr << "There is no more room to add the new employee!" << endl;
            throw exception();

        }
        Employee& theEmployee = mEmployees[mNextEmployeeSlot++];
        theEmployee.setFirstName(inFirstName);
        theEmployee.setLastName(inLastName);
        theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
        theEmployee.hire();
        return theEmployee;
    }
    Employee& Database::readEmployee(string inFirstName, string inLastName, int employeeNumber, int salary, bool hired)
    {
        Employee& theEmployee = mEmployees[mNextEmployeeSlot++];
        theEmployee.setFirstName(inFirstName);
        theEmployee.setLastName(inLastName);
        theEmployee.setEmployeeNumber(employeeNumber);
        theEmployee.setSalary(salary);
        if (hired) {
            theEmployee.hire();
        }
        else {
            theEmployee.fire();
        }
        return theEmployee;
    }
	Employee& Database::getEmployee(int inEmployeeNumber)
	{
		for (int i = 0; i < mNextEmployeeSlot; i++) {
			if (mEmployees[i].getEmployeeNumber() == inEmployeeNumber) {
				return mEmployees[i];
			}
		}
		cerr << "No employee with employee number " << inEmployeeNumber << endl;
		throw exception();
	}
	Employee& Database::getEmployee(string inFirstName, string inLastName)
	{
		for (int i = 0; i < mNextEmployeeSlot; i++) {
			if (mEmployees[i].getFirstName() == inFirstName &&
				mEmployees[i].getLastName() == inLastName) {
				return mEmployees[i];
			}
		}
		cerr << "No match with name " << inFirstName << " " << inLastName << endl;
		throw exception();
    }
    std::vector<Employee> Database::getAllEmployees() const {
        std::vector<Employee> allEmployees;
        for (int i = 0; i < mNextEmployeeSlot; i++) {
            allEmployees.push_back(mEmployees[i]);
        }
        return allEmployees;
    }

	Policy& Database::addPolicy(string inStartingDate, string endingDate, float inCost, int inTypeId, int inEmployeeId)
	{
		if (mNextPolicySlot >= kMaxPolicies) {
			cerr << "There is no more room to add the new policy!" << endl;
			throw exception();

		}
		Policy& thePolicy = mPolicies[mNextPolicySlot++];
		thePolicy.setPolicyNumber(mNextPolicyNumber++);
		thePolicy.setStartingDate(inStartingDate);
		thePolicy.setEndingDate(endingDate);
		thePolicy.setCost(inCost);
		thePolicy.setPayout(0);
		thePolicy.setPolicyTypeId(inTypeId);
		thePolicy.setClientId(mNextClientNumber++);
		thePolicy.setEmployeeId(inEmployeeId);
		return thePolicy;
	}

    Policy& Database::readPolicy(int policyId, string startDate, string endDate, int cost, int payout, int typeId, int clientId, int employeeId, bool paid, bool expired)
    {
        Policy& thePolicy = mPolicies[mNextPolicySlot++];
        thePolicy.setPolicyNumber(mNextPolicyNumber++);
        thePolicy.setStartingDate(startDate);
        thePolicy.setEndingDate(endDate);
        thePolicy.setCost(cost);
        thePolicy.setPayout(payout);
        thePolicy.setPolicyTypeId(typeId);
        thePolicy.setClientId(clientId);
        thePolicy.setEmployeeId(employeeId);
        if (paid) {
            thePolicy.markAsPaid();
        }
        else {
            thePolicy.markAsNotPaid();
        }
        if (expired) {
            thePolicy.markAsExpired();
        }
        else {
            thePolicy.markAsNotExpired();
        }
        return thePolicy;
    }

	Policy& Database::getPolicy(int inPolicyNumber)
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (mPolicies[i].getPolicyNumber() == inPolicyNumber) {
				return mPolicies[i];
			}
		}
		cerr << "No policy with policy number " << inPolicyNumber << endl;
		throw exception();
	}
    std::vector<Policy> Database::getAllPolicies() const {
        std::vector<Policy> allPolicies;
        for (int i = 0; i < mNextPolicySlot; i++) {
            allPolicies.push_back(mPolicies[i]);
        }
        return allPolicies;
    }
	void Database::displayAllPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			mPolicies[i].display();
		}
	}
	void Database::displayPaidPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (mPolicies[i].getIsPaid()) {
				mPolicies[i].display();
			}
		}
	}
	void Database::displayNotPaidPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (!mPolicies[i].getIsPaid()) {
				mPolicies[i].display();
			}
		}
	}
	void Database::displayExpiredPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (mPolicies[i].getIsExpired()) {
				mPolicies[i].display();
			}
		}
	}
	void Database::displayNotExpiredPolicies()
	{
		for (int i = 0; i < mNextPolicySlot; i++) {
			if (!mPolicies[i].getIsExpired()) {
				mPolicies[i].display();
			}
		}
	}
}
