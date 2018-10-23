
// Generated from /Users/rkoval/CLionProjects/Abstract_VM/avm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "avmParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by avmParser.
 */
class  avmListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(avmParser::ProgContext *ctx) = 0;
  virtual void exitProg(avmParser::ProgContext *ctx) = 0;

  virtual void enterLine(avmParser::LineContext *ctx) = 0;
  virtual void exitLine(avmParser::LineContext *ctx) = 0;

  virtual void enterComment(avmParser::CommentContext *ctx) = 0;
  virtual void exitComment(avmParser::CommentContext *ctx) = 0;

  virtual void enterEndofread(avmParser::EndofreadContext *ctx) = 0;
  virtual void exitEndofread(avmParser::EndofreadContext *ctx) = 0;

  virtual void enterInstruction(avmParser::InstructionContext *ctx) = 0;
  virtual void exitInstruction(avmParser::InstructionContext *ctx) = 0;

  virtual void enterOpcode(avmParser::OpcodeContext *ctx) = 0;
  virtual void exitOpcode(avmParser::OpcodeContext *ctx) = 0;

  virtual void enterValues(avmParser::ValuesContext *ctx) = 0;
  virtual void exitValues(avmParser::ValuesContext *ctx) = 0;

  virtual void enterType(avmParser::TypeContext *ctx) = 0;
  virtual void exitType(avmParser::TypeContext *ctx) = 0;

  virtual void enterArgument(avmParser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(avmParser::ArgumentContext *ctx) = 0;


};

