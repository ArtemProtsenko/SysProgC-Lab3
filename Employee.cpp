#include <iostream>
#include <string>
#include "Employee.h"

using namespace std;

namespace Records {
	Employee::Employee()
	{
		mFirstName = "";
		mLastName = "";
		mEmployeeNumber = -1;
		mSalary = kDefaultStartingSalary;
		fHired = false;
	}
	void Employee::promote(int inRaiseAmount)
	{
		setSalary(getSalary() + inRaiseAmount);
	}
	void Employee::demote(int inDemeritAmount)
	{
		setSalary(getSalary() - inDemeritAmount);
	}
	void Employee::hire()
	{
		fHired = true;
	}
	void Employee::fire()
	{
		fHired = false;
	}
    string Employee::getInfo()
	{
        return "Employee: " + getLastName() + ", " + getFirstName() +
               "\n-------------------------" +
               "\n" + (fHired ? "Current Employee" : "Former Employee") +
               "\nEmployee Number: " + std::to_string(getEmployeeNumber()) +
               "\nSalary: $" + std::to_string(getSalary()) +
               "\n||||||||||||||||||||||||||||||||||||||||||";
    }
	// Accessors and setters
	void Employee::setFirstName(string inFirstName)
	{
		mFirstName = inFirstName;
	}
	string Employee::getFirstName()
	{
		return mFirstName;
	}
	void Employee::setLastName(string inLastName)

	{
		mLastName = inLastName;
	}
	string Employee::getLastName()
	{
		return mLastName;
	}
	void Employee::setEmployeeNumber(int inEmployeeNumber)
	{
		mEmployeeNumber = inEmployeeNumber;
	}
	int Employee::getEmployeeNumber()
	{
		return mEmployeeNumber;
	}
	void Employee::setSalary(int inSalary)
	{
		mSalary = inSalary;
	}
	int Employee::getSalary()
	{
		return mSalary;
	}
	bool Employee::getIsHired()
	{
		return fHired;
	}
}
