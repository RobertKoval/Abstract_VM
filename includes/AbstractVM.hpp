//
// Created by Robert on 18.10.18.
//

#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include <vector>
#include "AbstractVMFactory.hpp"
#include <gen/avmParser.h>

class AbstractVM {
	public:
		AbstractVM();
		virtual ~AbstractVM();
		eOperandType getType(const std::string &) const;
		void calculate(avmParser::ProgContext *);
		void setDebugMode(bool _debugMode);
		bool isDebugMode() const;
		static eOperandType getBigerType(const eOperandType &a,
										 const eOperandType &b);
	private:
		AbstractVM(const AbstractVM &src);
		AbstractVM &operator=(const AbstractVM &src);
		void _push(eOperandType type, const std::string &value);
		void _pop(avmParser::LineContext *ctx);
		void _dump(avmParser::LineContext *ctx) const;
		bool _assert(avmParser::LineContext *ctx,
					 const eOperandType &type,
					 const std::string &value) const;
		void _add(avmParser::LineContext *ctx);
		void _sub(avmParser::LineContext *ctx);
		void _mul(avmParser::LineContext *ctx);
		void _div(avmParser::LineContext *ctx);
		void _mod(avmParser::LineContext *ctx);
		void _print(avmParser::LineContext *ctx) const;
		AbstractVMFactory             _factory;
		std::vector<const IOperand *> _stack;
		bool                          _debugMode;

};

#endif //ABSTRACTVMV1_ABSTRACTVM_HPP

