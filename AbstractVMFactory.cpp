//
// Created by Robert on 18.10.18.
//

#include <sstream>
#include "AbstractVMFactory.hpp"
#include "TNumber.hpp"

AbstractVMFactory::AbstractVMFactory() {}

AbstractVMFactory::~AbstractVMFactory() {

}

IOperand *AbstractVMFactory::create(const eOperandType type,
									const std::string &value) {

	long double intCheck; // int64

	if (type == OT_INT8) {
		intCheck = std::stold(value);
		if (intCheck > INT8_MAX) {
			throw std::overflow_error(
				"Error! value \"" + value + "\" overflow type int8!");
		}
		else if (intCheck < INT8_MIN) {
			throw std::underflow_error(
				"Error! value \"" + value + "\" underflow type int8!");
		}
		else {
			auto *newNumber = new TNumber<int8_t>(type,
												  static_cast<int8_t >(intCheck),
												  value);
			return newNumber;
		}

	}
	else if (type == OT_INT16) {
		intCheck = std::stold(value);
		if (intCheck > INT16_MAX) {
			throw std::overflow_error(
				"Error! value \"" + value + "\" overflow type int16!");
		}
		else if (intCheck < INT16_MIN) {
			throw std::underflow_error(
				"Error! value \"" + value + "\" underflow type int16!");
		}
		else {
			auto *newNumber = new TNumber<int16_t>(type,
												   static_cast<int16_t >(intCheck),
												   value);
			return newNumber;
		}

	}
	else if (type == OT_INT32) {
		intCheck = std::stold(value);
		if (intCheck > INT32_MAX) {
			throw std::overflow_error(
				"Error! value \"" + value + "\" overflow type int32!");
		}
		else if (intCheck < INT32_MIN) {
			throw std::underflow_error(
				"Error! value \"" + value + "\" underflow type int32!");
		}
		else {
			auto *newNumber = new TNumber<int32_t>(type,
												   static_cast<int32_t >(intCheck),
												   value);
			return newNumber;
		}
	}
	else if (type == OT_FLOAT) {
		float flCheck    = std::stof(value);
		auto  *newNumber = new TNumber<float>(type, flCheck, value);
		return newNumber;

	}
	else if (type == OT_DOUBLE) {
		double dCheck     = std::stod(value);
		auto   *newNumber = new TNumber<double>(type, dCheck, value);
		return newNumber;
	}
	return nullptr;
}


///TODO better overflow for float and double



///TODO float double overflow