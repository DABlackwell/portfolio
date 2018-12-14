/*
 * ProductionWorker.cpp
 *
 *  Created on: Nov 18, 2017; edited Nov 27, 2017
 *      Author: Daniel Brooks
 */

// Implementation file for the ProductionWorker class.
#include "ProductionWorker.h"
#include <iostream>
using namespace std;
/*
 * setShift function.
 * Sets the shift to 1 or 2. Other values throw an exception.
 */
void ProductionWorker::setShift(int sh) {
	if (sh == 1 || sh == 2) {
		shift = sh;
	}
	else {
		string exceptionString =
				"ERROR: Shift must be 1 (day) or 2 (night).\n";
		throw exceptionString;
	}
}
/*
 * setPayRate function.
 * A negative number will throw an exception.
 */
void ProductionWorker::setPayRate(double rt) {
	if (rt >= 0) {
		payRate = rt;
	}
	else {
		string exceptionString =
				"ERROR: Pay rate must be non-negative.\n";
		throw exceptionString;
	}
}
