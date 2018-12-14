/*
 * Employee.h
 *
 *  Created on: Nov 18, 2017; edited Nov 27, 2017
 *      Author: Daniel Brooks
 */

// Specification file for the Employee class.
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
class Employee {
	protected:
		string name;		// Employee name
		int empNum;		// Employee number
		string hireDate;	// Date hired
	public:
		// Constructors
		Employee() {
			name = ""; empNum = 0; hireDate = "";
		}
		Employee(string nm, int empN, string dt) {
			name = nm; setEmpNum(empN); hireDate = dt;
		}

		// Accessors
		string getName() const {
			return name;
		}
		int getEmpNum() const {
			return empNum;
		}
		string getHireDate() const {
			return hireDate;
		}

		// Mutators
		void setName(string nm) {
			name = nm;
		}
		void setEmpNum(int empN) {
			if (empN > 0 && empN < 9999) {
				empNum = empN;
			}
			else {
				string exceptionString =
						"ERROR: Employee number should be between 0 and 9999.\n";
				throw exceptionString;
			}
		}
		void setHireDate(string dt) {
			hireDate = dt;
		}
};
#endif /* EMPLOYEE_H */
