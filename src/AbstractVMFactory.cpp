//
// Created by Robert on 18.10.18.
//

#include <sstream>
#include <includes/AbstractVMFactory.hpp>

#include "../includes/AbstractVMFactory.hpp"
#include "includes/TOperand.hpp"

AbstractVMFactory::AbstractVMFactory() {}

AbstractVMFactory::~AbstractVMFactory() {

}

const IOperand *AbstractVMFactory::createOperand(eOperandType type,
												 const std::string &value) const {

	typedef const IOperand
		*(AbstractVMFactory::*Generators)(const std::string &) const;
	static const Generators gen[] = {&AbstractVMFactory::createInt8,
							   &AbstractVMFactory::createInt16,
							   &AbstractVMFactory::createInt32,
							   &AbstractVMFactory::createFloat,
							   &AbstractVMFactory::createDouble};

	return (this->*gen[type - 1])(value);
}

const IOperand *AbstractVMFactory::createInt8(const std::string &value) const {
	long double intCheck = std::stold(value);
	if (intCheck > INT8_MAX) {
		throw std::overflow_error(
			"Error! value \"" + value + "\" overflow type int8!");
	}
	else if (intCheck < INT8_MIN) {
		throw std::underflow_error(
			"Error! value \"" + value + "\" underflow type int8!");
	}
	else {
		auto *newNumber = new TOperand<int8_t>(OT_INT8,
											   static_cast<int8_t >(intCheck),
											   value);
		return newNumber;
	}
}

const IOperand *AbstractVMFactory::createInt16(const std::string &value) const {
	long double intCheck = std::stold(value);
	if (intCheck > INT16_MAX) {
		throw std::overflow_error(
			"Error! value \"" + value + "\" overflow type int16!");
	}
	else if (intCheck < INT16_MIN) {
		throw std::underflow_error(
			"Error! value \"" + value + "\" underflow type int16!");
	}
	else {
		auto *newNumber = new TOperand<int16_t>(OT_INT16,
												static_cast<int16_t >(intCheck),
												value);
		return newNumber;
	}
}

const IOperand *AbstractVMFactory::createInt32(const std::string &value) const {
	long double intCheck = std::stold(value);
	if (intCheck > INT32_MAX) {
		throw std::overflow_error(
			"Error! value \"" + value + "\" overflow type int32!");
	}
	else if (intCheck < INT32_MIN) {
		throw std::underflow_error(
			"Error! value \"" + value + "\" underflow type int32!");
	}
	else {
		auto *newNumber = new TOperand<int32_t>(OT_INT32,
												static_cast<int32_t >(intCheck),
												value);
		return newNumber;
	}
}

const IOperand *AbstractVMFactory::createFloat(const std::string &value) const {
	float flCheck    = std::stof(value);
	auto  *newNumber = new TOperand<float>(OT_FLOAT, flCheck, value);
	return newNumber;
}

const IOperand *AbstractVMFactory::createDouble(const std::string &value) const {
	double dCheck     = std::stod(value);
	auto   *newNumber = new TOperand<double>(OT_DOUBLE, dCheck, value);
	return newNumber;
}

AbstractVMFactory::AbstractVMFactory(const AbstractVMFactory &src) {
	*this = src;
}

AbstractVMFactory &AbstractVMFactory::operator=(const AbstractVMFactory &src) {
	static_cast<void>(src);
	return *this;
}


///TODO better overflow for float and double



///TODO float double overflow