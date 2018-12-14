/*
 * MathStack.h
 *
 *  Created on: Dec 5, 2017
 *      Author: Daniel Brooks
 */

// Specification file for the MathStack class
#ifndef MATHSTACK_H
#define MATHSTACK_H
#include "IntStack.h"

class MathStack : public IntStack
{
public:
   // Constructor
   MathStack(int s) : IntStack(s) {}

   // MathStack operations
   void add();
   void sub();
   void mult();
   void div();
   void addAll();
   void multAll();
};
/* ===========================================
 * Member function add. add pops the first
 * two values off the stack and adds them.
 * The sum is pushed onto the stack.
 * ===========================================
 */
void MathStack::add() {
   int num, sum;

   // Pop the first two values off the stack.
   pop(sum);
   pop(num);

   // Add the two values, store in sum.
   sum += num;

   // Push sum back onto the stack.
   push(sum);
}
/* ===========================================
 * Member function sub. sub pops the first two
 * values off the stack. The second value is
 * subtracted from the first value. The
 * difference is pushed onto the stack.
 * ===========================================
 */
void MathStack::sub() {
   int num, diff;

   // Pop the first two values off the stack.
   pop(diff);
   pop(num);

   // Subtract num from diff.
   diff -= num;

   // Push diff back onto the stack.
   push(diff);
}
/* ===========================================
 * Member function mult. mult pops the first
 * two values off the stack and multiplies
 * them. The product is pushed onto the stack.
 * ===========================================
 */
void MathStack::mult() {
   int num, prod;

   // Pop the first two values off the stack.
   pop(prod);
   pop(num);

   // Multiply the two values, store in prod.
   prod *= num;

   // Push prod back onto the stack.
   push(prod);
}
/* ===========================================
 * Member function div. div pops the first two
 * values off the stack. The second value is
 * divided by the first value. The
 * quotient is pushed onto the stack.
 * Note this is integer division (drops
 * remainder).
 * ===========================================
 */
void MathStack::div() {
   int num, quot;

   // Pop the first two values off the stack.
   pop(quot);
   pop(num);

   // Add the two values, store in sum.
   quot /= num;

   // Push sum back onto the stack.
   push(quot);
}
/* ===========================================
 * Member function addAll. addAll pops every
 * value off the stack and adds them. The sum
 * is pushed onto the stack.
 * ===========================================
 */
void MathStack::addAll() {
	int sum, num;
	pop(sum);

	while (!isEmpty()) {
		pop(num);
		sum += num;
	}

	// Push sum back onto the stack.
	push(sum);
}
/* ===========================================
 * Member function multAll. multAll pops every
 * value off the stack and multiplies them.
 * The product is pushed onto the stack.
 * ===========================================
 */
void MathStack::multAll() {
	int num, prod;
	pop(prod);

	while (!isEmpty()) {
		pop(num);
		prod *= num;
	}

	// Push prod back onto the stack.
	push(prod);
}
#endif
