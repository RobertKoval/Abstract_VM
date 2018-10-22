//
// Created by Robert on 18.10.18.
//

#ifndef TNUMBER_HPP
#define TNUMBER_HPP

#include <cmath>
#include "AbstractVMFactory.hpp"
#include "AbstractVM.hpp"

template <typename T>
class TOperand : public IOperand {
	public:
		TOperand(eOperandType type,
				 T value,
				 const std::string &valueString) : _type(type), _value(value),
												   _valueString(valueString) {}

		virtual ~TOperand() {}

		int getPrecision() const override {return _type;}

		eOperandType getType() const override {return _type;}

		const IOperand *operator+(IOperand const &rhs) const override {
			eOperandType s = AbstractVM::getBigerType(getType(), rhs.getType());

			if (s <= OT_INT32) {
				int64_t tmp = std::stol(this->_valueString)
					+ std::stol(rhs.toString());
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			else if (s <= OT_DOUBLE) {
				long double tmp = std::stod(this->_valueString)
					+ std::stod(rhs.toString());
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			return nullptr;
		}

		const IOperand *operator-(IOperand const &rhs) const override {
			eOperandType s = AbstractVM::getBigerType(getType(), rhs.getType());

			if (s <= OT_INT32) {
				int64_t
					tmp = std::stol(_valueString) - std::stol(rhs.toString());
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			else if (s <= OT_DOUBLE) {
				long double
					tmp = std::stod(_valueString) - std::stod(rhs.toString());
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			return nullptr;
		}

		const IOperand *operator*(IOperand const &rhs) const override {
			eOperandType s = AbstractVM::getBigerType(getType(), rhs.getType());

			if (s <= OT_INT32) {
				int64_t tmp = std::stol(this->_valueString)
					* std::stol(rhs.toString());
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			else if (s <= OT_DOUBLE) {
				long double tmp = std::stod(this->_valueString)
					* std::stod(rhs.toString());
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			return nullptr;
		}

		const IOperand *operator/(IOperand const &rhs) const override {
			eOperandType s = AbstractVM::getBigerType(getType(), rhs.getType());

			if (s <= OT_INT32) {
				if (rhs.toString() == "0") {
					throw std::invalid_argument("Error! Cant't devide by 0");
				}
				int64_t tmp = std::stol(this->_valueString)
					/ std::stol(rhs.toString());
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			else if (s <= OT_DOUBLE) {
				if (rhs.toString() == "0") {
					throw std::invalid_argument("Error! Cant't devide by 0");
				}
				long double tmp = std::stod(this->_valueString)
					/ std::stod(rhs.toString());
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			return nullptr;
		}

		const IOperand *operator%(IOperand const &rhs) const override {
			eOperandType s = AbstractVM::getBigerType(getType(), rhs.getType());

			if (s <= OT_INT32) {
				if (rhs.toString() == "0") {
					throw std::invalid_argument("Error! Cant't mod by 0");
				}
				int64_t tmp = std::stol(this->_valueString)
					% std::stol(rhs.toString());
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			else if (s <= OT_DOUBLE) {
				if (rhs.toString() == "0") {
					throw std::invalid_argument("Error! Cant't mod by 0");
				}
				long double tmp = fmod(std::stod(this->_valueString),
									   std::stod(rhs.toString()));
				return (_fac.createOperand(s, std::to_string(tmp)));
			}
			return nullptr;
		}

		const std::string &toString() const override {return _valueString;}

	private:
		eOperandType      _type;
		T                 _value;
		std::string       _valueString;
		AbstractVMFactory _fac;

};

#endif
