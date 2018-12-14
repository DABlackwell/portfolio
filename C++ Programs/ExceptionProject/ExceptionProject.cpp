/*	Daniel Brooks
	© 2017-11-27
	Chapter 16 Assignment (Programming Challenge #13)

	ExceptionProject.cpp
	Description:	This program demonstrates the exceptions thrown by the
				Employee and ProductionWorker classes.
*/

#include <iostream>
#include <iomanip>
#include "ProductionWorker.h"
using namespace std;

int main() {
	bool tryAgain = true;	// Try input again
	int intInput = 0;		// Holds user int input
	double empPayRate;		// Holds user pay rate input
	string stringInput;		// Holds user string input

	// Create ProductionWorker object.
	ProductionWorker myEmployee;

	// Get employee data from the user.
	cout << "Enter your full name: ";
	getline(cin, stringInput);
	myEmployee.setName(stringInput);

	cout << "Enter your employee number: ";
	cin  >> intInput;
	do {
		try {
			myEmployee.setEmpNum(intInput);
			tryAgain = false;
		}
		catch (string &exceptionString) {
			cout << exceptionString;
			cout << "Please enter a valid employee number: ";
			cin  >> intInput;
		}
	} while (tryAgain);

	cout << "Enter your hire date: ";
	cin.ignore();
	getline(cin, stringInput);
	myEmployee.setHireDate(stringInput);

	tryAgain = true;
	cout << "Enter your shift (1 for day, 2 for night): ";
	cin  >> intInput;
	do {
		try {
			myEmployee.setShift(intInput);
			tryAgain = false;
		}
		catch (string &exceptionString) {
			cout << exceptionString;
			cout << "Please enter a valid shift: ";
			cin  >> intInput;
		}
	} while (tryAgain);

	tryAgain = true;
	cout << "Enter your hourly pay rate: $";
	cin  >> empPayRate;
	do {
		try {
			myEmployee.setPayRate(empPayRate);
			tryAgain = false;
		}
		catch (string &exceptionString) {
			cout << exceptionString;
			cout << "Please enter a valid pay rate: ";
			cin  >> empPayRate;
		}
	} while (tryAgain);

	cout << "\nYOUR EMPLOYEE INFO:\n"
		 << "  Name: " << myEmployee.getName() << endl
		 << "  Employee #: " << myEmployee.getEmpNum() << endl
		 << "  Hire date: " << myEmployee.getHireDate() << endl;
	if (myEmployee.getShift() == 1)
		cout << "  Day shift\n";
	else
		cout << "  Night shift\n";
	cout << showpoint << fixed << setprecision(2);
	cout << "  Pay rate: $" << myEmployee.getPayRate() << "/hr" << endl;

	return 0;
}
