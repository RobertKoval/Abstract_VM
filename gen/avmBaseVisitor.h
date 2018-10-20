
// Generated from /Users/rkoval/CLionProjects/AbstractVMv1/avm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "avmVisitor.h"


/**
 * This class provides an empty implementation of avmVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  avmBaseVisitor : public avmVisitor {
public:

  virtual antlrcpp::Any visitProg(avmParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLine(avmParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComment(avmParser::CommentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEndofread(avmParser::EndofreadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstruction(avmParser::InstructionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpcode(avmParser::OpcodeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValues(avmParser::ValuesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(avmParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgument(avmParser::ArgumentContext *ctx) override {
    return visitChildren(ctx);
  }


};

