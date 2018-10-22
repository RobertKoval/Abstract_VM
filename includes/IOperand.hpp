//
// Created by Robert on 16.10.18.
//

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <iostream>
typedef enum {
	OT_UNDEFINED = 0,
	OT_INT8,
	OT_INT16,
	OT_INT32,
	OT_FLOAT,
	OT_DOUBLE
}eOperandType;

class IOperand {
	public:
		virtual int getPrecision(void) const = 0; // Precision of the type of the instance
		virtual eOperandType getType(void) const = 0; // Type of the instance
		virtual IOperand const *operator+(IOperand const &rhs) const = 0; // Sum
		virtual IOperand const *operator-(IOperand const &rhs) const = 0; // Difference
		virtual IOperand const *operator*(IOperand const &rhs) const = 0; // Product
		virtual IOperand const *operator/(IOperand const &rhs) const = 0; // Quotient
		virtual IOperand const *operator%(IOperand const &rhs) const = 0; // Modulo
		virtual std::string const &toString(void) const = 0; // String representation of the instance
		virtual ~IOperand(void) {}
};

#endif
