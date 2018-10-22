//
// Created by Robert on 18.10.18.
//

#include "includes/AbstractVM.hpp"

AbstractVM::AbstractVM() : _debugMode(false) {}

AbstractVM::~AbstractVM() {}

eOperandType AbstractVM::getType(const std::string &type) const {
	if (type == "int8") {return (OT_INT8);}
	else if (type == "int16") {return (OT_INT16);}
	else if (type == "int32") {return (OT_INT32);}
	else if (type == "float") {return (OT_FLOAT);}
	else if (type == "double") {return (OT_DOUBLE);}
	return (OT_UNDEFINED);
}

eOperandType AbstractVM::getBigerType(const eOperandType &a,
									  const eOperandType &b) {
	return a > b ? a : b;
}

void AbstractVM::setDebugMode(bool _debugMode) {
	AbstractVM::_debugMode = _debugMode;
}

bool AbstractVM::isDebugMode() const {return _debugMode;}

void AbstractVM::calculate(avmParser::ProgContext *ctx) {
	for (auto line : ctx->line()) {
		if (line->instruction()) {
			std::string opcode = line->instruction()->opcode()->getText();
			if (opcode == "push" && line->instruction()->values()) {
				_push(getType(line->instruction()->values()->type()->getText()),
					  line->instruction()->values()->argument()->getText());
			}
			else if (opcode == "exit") {
				for (auto i : _stack) {delete i;}
				return;
			}
			else if (opcode == "pop") {_pop(line);} //
			else if (opcode == "dump") {_dump(line);}//
			else if (opcode == "assert") {
				_assert(line,
						getType(line->instruction()->values()->type()
									->getText()),
						line->instruction()->values()->argument()->getText());
			}
			else if (opcode == "add") {_add(line);}
			else if (opcode == "sub") {_sub(line);}
			else if (opcode == "mul") {_mul(line);}
			else if (opcode == "div") {_div(line);}
			else if (opcode == "mod") {_mod(line);}
			else if (opcode == "print") {_print(line);}
		}
	}
	if (!_debugMode) {
		throw std::logic_error("Error! No \"exit\" command at the end of file! Undefined behavior!");
	}
	else {
		std::cout << "Error! No \"exit\" command at the end of file! Undefined behavior!"
				  << std::endl;
	}
}

void AbstractVM::_push(eOperandType type, const std::string &value) {
	_stack.push_back(_factory.createOperand(type, value));
}

void AbstractVM::_pop(avmParser::LineContext *ctx) {
	if (_stack.empty() && !_debugMode) {
		throw std::range_error(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Stack is empty!");
	}
	else if (_stack.empty() && _debugMode) {
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Stack is empty!" << std::endl;
	}
	else {
		delete _stack.back();
		_stack.pop_back();
	}
}

void AbstractVM::_dump(avmParser::LineContext *ctx) const {
	if (_stack.empty() && !isDebugMode()) {
		throw std::out_of_range(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Stack is empty.");
	}
	else if (_stack.empty() && isDebugMode()) {
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Stack is empty." << std::endl;
	}
	else {
		for (auto el = _stack.crbegin(); el != _stack.crend(); el++) {
			std::cout << el[0]->toString() << std::endl;
		}
	}
}

bool AbstractVM::_assert(avmParser::LineContext *ctx,
						 const eOperandType &type,
						 const std::string &value) const {

	if (_stack.empty())
		return false;
	else if (_stack.back()->toString() == value
		&& _stack.back()->getType() == type) {return true;}
	else if (!_debugMode) {
		throw std::invalid_argument(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Value \"" + value + "\" with type \""
				+ ctx->instruction()->values()->type()->getText()
				+ "\" not exist!");
	}
	else if (_debugMode) {
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Value \"" + value + "\" with type \""
			+ ctx->instruction()->values()->type()->getText() + "\" not exist!"
				  << std::endl;
	}
	return false;
}

void AbstractVM::_add(avmParser::LineContext *ctx) {
	if (_stack.size() < 2 && !_debugMode) {
		throw std::range_error(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Must be minimum 2 elements in stack.");
	}
	else if (_stack.size() < 2 && _debugMode) {
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Must be minimum 2 elements in stack." << std::endl;
		return;
	}

	const IOperand *rhv = _stack.end()[-1];
	const IOperand *lhv = _stack.end()[-2];

	eOperandType t = getBigerType(lhv->getType(), rhv->getType());
	auto         a = *lhv + *rhv;

	_pop(ctx);
	_pop(ctx);

	_push(t, a->toString());

	delete a;
}

void AbstractVM::_sub(avmParser::LineContext *ctx) {
	if (_stack.size() < 2 && !_debugMode) {
		throw std::range_error(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Must be minimum 2 elements in stack.");
	}
	else if (_stack.size() < 2 && _debugMode) {
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Must be minimum 2 elements in stack." << std::endl;
		return;
	}
	const IOperand *rhv = _stack.end()[-1];
	const IOperand *lhv = _stack.end()[-2];

	eOperandType t = getBigerType(lhv->getType(), rhv->getType());
	auto         a = *lhv - *rhv;

	_pop(ctx);
	_pop(ctx);

	_push(t, a->toString());

	delete a;
}

void AbstractVM::_mul(avmParser::LineContext *ctx) {
	if (_stack.size() < 2 && !_debugMode) {
		throw std::range_error(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Must be minimum 2 elements in stack.");
	}
	else if (_stack.size() < 2 && _debugMode) {
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Must be minimum 2 elements in stack." << std::endl;
		return;
	}

	const IOperand *rhv = _stack.end()[-1];
	const IOperand *lhv = _stack.end()[-2];

	eOperandType t = getBigerType(lhv->getType(), rhv->getType());
	auto         a = *lhv * *rhv;

	_pop(ctx);
	_pop(ctx);

	_push(t, a->toString());

	delete a;
}

void AbstractVM::_div(avmParser::LineContext *ctx) {
	if (_stack.size() < 2 && !_debugMode) {
		throw std::range_error(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Must be minimum 2 elements in stack.");
	}
	else if (_stack.size() < 2 && _debugMode) {
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Must be minimum 2 elements in stack." << std::endl;
		return;
	}

	const IOperand *rhv = _stack.end()[-1];
	const IOperand *lhv = _stack.end()[-2];

	eOperandType t = getBigerType(lhv->getType(), rhv->getType());
	auto         a = *lhv / *rhv;

	_pop(ctx);
	_pop(ctx);

	_push(t, a->toString());

	delete a;
}

void AbstractVM::_mod(avmParser::LineContext *ctx) {
	if (_stack.size() < 2 && !_debugMode) {
		throw std::range_error(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Must be minimum 2 elements in stack.");
	}
	else if (_stack.size() < 2 && _debugMode) {
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Must be minimum 2 elements in stack." << std::endl;
		return;
	}
	const IOperand *rhv = _stack.end()[-1];
	const IOperand *lhv = _stack.end()[-2];

	eOperandType t = getBigerType(lhv->getType(), rhv->getType());
	auto         a = *lhv % *rhv;

	_pop(ctx);
	_pop(ctx);

	_push(t, a->toString());

	delete a;
}

void AbstractVM::_print(avmParser::LineContext *ctx) const {
	if (_stack.empty() && !isDebugMode()) {
		throw std::out_of_range(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Stack is empty.");
	} else if (_stack.empty() && isDebugMode())
	{
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Stack is empty." << std::endl;
		return;
	}
	const IOperand *head = _stack.back();
	if (head->getType() == OT_INT8) {
		std::cout << static_cast<char>(std::stoi(head->toString()))
				  << std::endl;
	}
	else if (!_debugMode) {
		throw std::invalid_argument(
			"Error in line: " + std::to_string(ctx->start->getLine())
				+ ". Value with type \""
				+ ctx->instruction()->values()->type()->getText()
				+ "\" not exist!");
	}
	else if (_debugMode) {
		std::cout << "Error in line: " + std::to_string(ctx->start->getLine())
			+ ". Value with type \""
			+ ctx->instruction()->values()->type()->getText() + "\" not exist!"
				  << std::endl;
	}
}
