
// Generated from /Users/rkoval/CLionProjects/AbstractVMv1/avm.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "avmListener.h"

/**
 * This class provides an empty implementation of avmListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  avmBaseListener : public avmListener {
public:

  virtual void enterProg(avmParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(avmParser::ProgContext * /*ctx*/) override { }

  virtual void enterLine(avmParser::LineContext * /*ctx*/) override { }
  virtual void exitLine(avmParser::LineContext * /*ctx*/) override { }

  virtual void enterComment(avmParser::CommentContext * /*ctx*/) override { }
  virtual void exitComment(avmParser::CommentContext * /*ctx*/) override { }

  virtual void enterEndofread(avmParser::EndofreadContext * /*ctx*/) override { }
  virtual void exitEndofread(avmParser::EndofreadContext * /*ctx*/) override { }

  virtual void enterInstruction(avmParser::InstructionContext * /*ctx*/) override { }
  virtual void exitInstruction(avmParser::InstructionContext * /*ctx*/) override { }

  virtual void enterOpcode(avmParser::OpcodeContext * /*ctx*/) override { }
  virtual void exitOpcode(avmParser::OpcodeContext * /*ctx*/) override { }

  virtual void enterValues(avmParser::ValuesContext * /*ctx*/) override { }
  virtual void exitValues(avmParser::ValuesContext * /*ctx*/) override { }

  virtual void enterType(avmParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(avmParser::TypeContext * /*ctx*/) override { }

  virtual void enterArgument(avmParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(avmParser::ArgumentContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

