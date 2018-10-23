//
// Created by Robert on 18.10.18.
//

#ifndef ABSTRACTVMFACTORY_HPP
#define ABSTRACTVMFACTORY_HPP

#include "IOperand.hpp"

class AbstractVMFactory {
	public:
		AbstractVMFactory();
		virtual ~AbstractVMFactory();

		const IOperand *createOperand(eOperandType type,
									  const std::string &value) const;
	private:
		AbstractVMFactory(const AbstractVMFactory &src);
		AbstractVMFactory &operator=(const AbstractVMFactory &src);
		const IOperand *createInt8(const std::string &value) const;
		const IOperand *createInt16(const std::string &value) const;
		const IOperand *createInt32(const std::string &value) const;
		const IOperand *createFloat(const std::string &value) const;
		const IOperand *createDouble(const std::string &value) const;
};

#endif //ABSTRACTVMFACTORY_HPP
