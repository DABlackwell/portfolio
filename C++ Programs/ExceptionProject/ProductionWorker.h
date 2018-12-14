/*
 * ProductionWorker.h
 *
 *  Created on: Nov 18, 2017; edited Nov 27, 2017
 *      Author: Daniel Brooks
 */

// Specification file for the ProductionWorker class.
#ifndef PRODUCTIONWORKER_H
#define PRODUCTIONWORKER_H
#include "Employee.h"
class ProductionWorker : public Employee {
	protected:
		int shift;		// Day shift (1) or night shift (2)
		double payRate;	// Hourly pay rate
	public:
		// Constructors
		ProductionWorker() : Employee() {
			shift = 0; payRate = 0.0;
		}
		ProductionWorker(string nm, int empN, string dt, int sh, double rt) :
			Employee(nm, empN, dt) {
			shift = sh; setPayRate(rt);
		}

		// Accessors
		int getShift() const {
			return shift;
		}
		double getPayRate() const {
			return payRate;
		}

		// Mutators; defined in implementation file.
		void setShift(int);
		void setPayRate(double);
};
#endif /* PRODUCTIONWORKER_H */
