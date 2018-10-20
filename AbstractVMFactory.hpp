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
		static IOperand* create(eOperandType type, const std::string &value);
};

#endif //ABSTRACTVMFACTORY_HPP
