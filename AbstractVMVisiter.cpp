//
// Created by Robert on 18.10.18.
//

#include "AbstractVMVisiter.hpp"

antlrcpp::Any AbstractVMVisiter::visitProg(avmParser::ProgContext *ctx) {
	return avmBaseVisitor::visitProg(ctx);
}


antlrcpp::Any AbstractVMVisiter::visitLine(avmParser::LineContext *ctx) {
	return avmBaseVisitor::visitLine(ctx);
}

antlrcpp::Any AbstractVMVisiter::visitInstruction(avmParser::InstructionContext *ctx) {
	return avmBaseVisitor::visitInstruction(ctx);
}

antlrcpp::Any AbstractVMVisiter::visitValues(avmParser::ValuesContext *ctx) {
	return avmBaseVisitor::visitValues(ctx);
}

antlrcpp::Any AbstractVMVisiter::visitArgument(avmParser::ArgumentContext *ctx) {
	return avmBaseVisitor::visitArgument(ctx);
}

