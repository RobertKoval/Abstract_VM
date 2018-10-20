
// Generated from /Users/rkoval/CLionProjects/AbstractVMv1/avm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "avmParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by avmParser.
 */
class  avmVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by avmParser.
   */
    virtual antlrcpp::Any visitProg(avmParser::ProgContext *context) = 0;

    virtual antlrcpp::Any visitLine(avmParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitComment(avmParser::CommentContext *context) = 0;

    virtual antlrcpp::Any visitEndofread(avmParser::EndofreadContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(avmParser::InstructionContext *context) = 0;

    virtual antlrcpp::Any visitOpcode(avmParser::OpcodeContext *context) = 0;

    virtual antlrcpp::Any visitValues(avmParser::ValuesContext *context) = 0;

    virtual antlrcpp::Any visitType(avmParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitArgument(avmParser::ArgumentContext *context) = 0;


};

