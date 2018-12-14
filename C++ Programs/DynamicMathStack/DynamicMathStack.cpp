/*	Daniel Brooks
	© 2017-12-05
	Chapter 19 Assignment - Programming Challenge #7

	DynamicMathStack.cpp
	Description:	This program tests the modified MathStack class.
*/

#include <iostream>
#include <iomanip>
#include "MathStack.h"
using namespace std;

int main() {
	int catchVar;	// To hold values popped off the stack.

	// Create a MathStack object.
	MathStack stack(5);

	/* =================
	 * ADD FUNCTION TEST
	 * =================
	 */
	// Push 3 and 6 onto the stack.
	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 6\n";
	stack.push(6);

	// Add the two values.
	stack.add();

	// Pop the sum off the stack and display it.
	cout << "The sum is ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	/* =================
	 * SUB FUNCTION TEST
	 * =================
	 */
	// Push 7 and 10 onto the stack.
	cout << "Pushing 7\n";
	stack.push(7);
	cout << "Pushing 10\n";
	stack.push(10);

	// Subtract 7 from 10.
	stack.sub();

	// Pop the difference off the stack and display it.
	cout << "The difference is: ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	/* ==================
	 * MULT FUNCTION TEST
	 * ==================
	 */
	// Push 4 and 9 onto the stack.
	cout << "Pushing 4\n";
	stack.push(4);
	cout << "Pushing 9\n";
	stack.push(9);

	// Multiply the two values.
	stack.mult();

	// Pop the sum off the stack and display it.
	cout << "The product is ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	/* =================
	 * DIV FUNCTION TEST
	 * =================
	 */
	// Push 3 and 12 onto the stack.
	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 12\n";
	stack.push(12);

	// Divide 12 by 3.
	stack.div();

	// Pop the difference off the stack and display it.
	cout << "The quotient is: ";
	cout << showpoint << setprecision(2);
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	/* ====================
	 * ADDALL FUNCTION TEST
	 * ====================
	 */
	// Push 4, 8, and 12 onto the stack.
	cout << "Pushing 4\n";
	stack.push(4);
	cout << "Pushing 8\n";
	stack.push(8);
	cout << "Pushing 12\n";
	stack.push(12);

	// Add all the values in the stack.
	stack.addAll();

	// Pop the sum off the stack and display it.
	cout << "The sum is ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	/* =====================
	 * MULTALL FUNCTION TEST
	 * =====================
	 */
	// Push 3, 4, and 5 onto the stack.
	cout << "Pushing 3\n";
	stack.push(3);
	cout << "Pushing 4\n";
	stack.push(4);
	cout << "Pushing 5\n";
	stack.push(5);

	// Add the two values.
	stack.multAll();

	// Pop the sum off the stack and display it.
	cout << "The product is ";
	stack.pop(catchVar);
	cout << catchVar << endl << endl;

	return 0;
}
