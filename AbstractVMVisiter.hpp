//
// Created by Robert on 18.10.18.
//

#ifndef ABSTRACTVMV1_ABSTRACTVMVISITER_HPP
#define ABSTRACTVMV1_ABSTRACTVMVISITER_HPP

#include <gen/avmBaseVisitor.h>

class AbstractVMVisiter : public avmBaseVisitor {
	public:
		antlrcpp::Any visitProg(avmParser::ProgContext *ctx);
		antlrcpp::Any visitLine(avmParser::LineContext *ctx);
		antlrcpp::Any visitInstruction(avmParser::InstructionContext *ctx);
		antlrcpp::Any visitValues(avmParser::ValuesContext *ctx);
		antlrcpp::Any visitArgument(avmParser::ArgumentContext *ctx);
};

#endif //ABSTRACTVMV1_ABSTRACTVMVISITER_HPP
