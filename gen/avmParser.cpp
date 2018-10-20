
// Generated from /Users/rkoval/CLionProjects/AbstractVMv1/avm.g4 by ANTLR 4.7


#include "avmListener.h"
#include "avmVisitor.h"

#include "avmParser.h"


using namespace antlrcpp;
using namespace antlr4;

avmParser::avmParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

avmParser::~avmParser() {
  delete _interpreter;
}

std::string avmParser::getGrammarFileName() const {
  return "avm.g4";
}

const std::vector<std::string>& avmParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& avmParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

avmParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* avmParser::ProgContext::EOF() {
  return getToken(avmParser::EOF, 0);
}

std::vector<avmParser::LineContext *> avmParser::ProgContext::line() {
  return getRuleContexts<avmParser::LineContext>();
}

avmParser::LineContext* avmParser::ProgContext::line(size_t i) {
  return getRuleContext<avmParser::LineContext>(i);
}


size_t avmParser::ProgContext::getRuleIndex() const {
  return avmParser::RuleProg;
}

void avmParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void avmParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


antlrcpp::Any avmParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<avmVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

avmParser::ProgContext* avmParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, avmParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << avmParser::T__0)
      | (1ULL << avmParser::T__1)
      | (1ULL << avmParser::T__2)
      | (1ULL << avmParser::T__3)
      | (1ULL << avmParser::T__4)
      | (1ULL << avmParser::T__5)
      | (1ULL << avmParser::T__6)
      | (1ULL << avmParser::T__7)
      | (1ULL << avmParser::T__8)
      | (1ULL << avmParser::T__9)
      | (1ULL << avmParser::T__10)
      | (1ULL << avmParser::COMMENT)
      | (1ULL << avmParser::EOL)
      | (1ULL << avmParser::ENDOFREAD)
      | (1ULL << avmParser::TAB))) != 0)) {
      setState(18);
      line();
      setState(23);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(24);
    match(avmParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

avmParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

avmParser::CommentContext* avmParser::LineContext::comment() {
  return getRuleContext<avmParser::CommentContext>(0);
}

avmParser::InstructionContext* avmParser::LineContext::instruction() {
  return getRuleContext<avmParser::InstructionContext>(0);
}

avmParser::EndofreadContext* avmParser::LineContext::endofread() {
  return getRuleContext<avmParser::EndofreadContext>(0);
}

tree::TerminalNode* avmParser::LineContext::EOL() {
  return getToken(avmParser::EOL, 0);
}

tree::TerminalNode* avmParser::LineContext::TAB() {
  return getToken(avmParser::TAB, 0);
}

tree::TerminalNode* avmParser::LineContext::SP() {
  return getToken(avmParser::SP, 0);
}


size_t avmParser::LineContext::getRuleIndex() const {
  return avmParser::RuleLine;
}

void avmParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void avmParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


antlrcpp::Any avmParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<avmVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

avmParser::LineContext* avmParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, avmParser::RuleLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == avmParser::TAB) {
      setState(26);
      match(avmParser::TAB);
    }
    setState(42);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case avmParser::COMMENT: {
        setState(29);
        comment();
        break;
      }

      case avmParser::T__0:
      case avmParser::T__1:
      case avmParser::T__2:
      case avmParser::T__3:
      case avmParser::T__4:
      case avmParser::T__5:
      case avmParser::T__6:
      case avmParser::T__7:
      case avmParser::T__8:
      case avmParser::T__9:
      case avmParser::T__10: {
        setState(30);
        instruction();
        setState(32);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == avmParser::SP) {
          setState(31);
          match(avmParser::SP);
        }
        setState(35);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          setState(34);
          comment();
          break;
        }

        }
        setState(38);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          setState(37);
          match(avmParser::EOL);
          break;
        }

        }
        break;
      }

      case avmParser::ENDOFREAD: {
        setState(40);
        endofread();
        break;
      }

      case avmParser::EOL: {
        setState(41);
        match(avmParser::EOL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentContext ------------------------------------------------------------------

avmParser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* avmParser::CommentContext::COMMENT() {
  return getToken(avmParser::COMMENT, 0);
}


size_t avmParser::CommentContext::getRuleIndex() const {
  return avmParser::RuleComment;
}

void avmParser::CommentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComment(this);
}

void avmParser::CommentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComment(this);
}


antlrcpp::Any avmParser::CommentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<avmVisitor*>(visitor))
    return parserVisitor->visitComment(this);
  else
    return visitor->visitChildren(this);
}

avmParser::CommentContext* avmParser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 4, avmParser::RuleComment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    match(avmParser::COMMENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndofreadContext ------------------------------------------------------------------

avmParser::EndofreadContext::EndofreadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* avmParser::EndofreadContext::ENDOFREAD() {
  return getToken(avmParser::ENDOFREAD, 0);
}


size_t avmParser::EndofreadContext::getRuleIndex() const {
  return avmParser::RuleEndofread;
}

void avmParser::EndofreadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEndofread(this);
}

void avmParser::EndofreadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEndofread(this);
}


antlrcpp::Any avmParser::EndofreadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<avmVisitor*>(visitor))
    return parserVisitor->visitEndofread(this);
  else
    return visitor->visitChildren(this);
}

avmParser::EndofreadContext* avmParser::endofread() {
  EndofreadContext *_localctx = _tracker.createInstance<EndofreadContext>(_ctx, getState());
  enterRule(_localctx, 6, avmParser::RuleEndofread);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(avmParser::ENDOFREAD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

avmParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

avmParser::OpcodeContext* avmParser::InstructionContext::opcode() {
  return getRuleContext<avmParser::OpcodeContext>(0);
}

tree::TerminalNode* avmParser::InstructionContext::SP() {
  return getToken(avmParser::SP, 0);
}

avmParser::ValuesContext* avmParser::InstructionContext::values() {
  return getRuleContext<avmParser::ValuesContext>(0);
}

tree::TerminalNode* avmParser::InstructionContext::EOL() {
  return getToken(avmParser::EOL, 0);
}


size_t avmParser::InstructionContext::getRuleIndex() const {
  return avmParser::RuleInstruction;
}

void avmParser::InstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstruction(this);
}

void avmParser::InstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstruction(this);
}


antlrcpp::Any avmParser::InstructionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<avmVisitor*>(visitor))
    return parserVisitor->visitInstruction(this);
  else
    return visitor->visitChildren(this);
}

avmParser::InstructionContext* avmParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 8, avmParser::RuleInstruction);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(56);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(48);
      opcode();
      setState(49);
      match(avmParser::SP);
      setState(50);
      values();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(52);
      opcode();
      setState(54);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(53);
        match(avmParser::EOL);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpcodeContext ------------------------------------------------------------------

avmParser::OpcodeContext::OpcodeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t avmParser::OpcodeContext::getRuleIndex() const {
  return avmParser::RuleOpcode;
}

void avmParser::OpcodeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOpcode(this);
}

void avmParser::OpcodeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOpcode(this);
}


antlrcpp::Any avmParser::OpcodeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<avmVisitor*>(visitor))
    return parserVisitor->visitOpcode(this);
  else
    return visitor->visitChildren(this);
}

avmParser::OpcodeContext* avmParser::opcode() {
  OpcodeContext *_localctx = _tracker.createInstance<OpcodeContext>(_ctx, getState());
  enterRule(_localctx, 10, avmParser::RuleOpcode);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << avmParser::T__0)
      | (1ULL << avmParser::T__1)
      | (1ULL << avmParser::T__2)
      | (1ULL << avmParser::T__3)
      | (1ULL << avmParser::T__4)
      | (1ULL << avmParser::T__5)
      | (1ULL << avmParser::T__6)
      | (1ULL << avmParser::T__7)
      | (1ULL << avmParser::T__8)
      | (1ULL << avmParser::T__9)
      | (1ULL << avmParser::T__10))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValuesContext ------------------------------------------------------------------

avmParser::ValuesContext::ValuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

avmParser::TypeContext* avmParser::ValuesContext::type() {
  return getRuleContext<avmParser::TypeContext>(0);
}

avmParser::ArgumentContext* avmParser::ValuesContext::argument() {
  return getRuleContext<avmParser::ArgumentContext>(0);
}


size_t avmParser::ValuesContext::getRuleIndex() const {
  return avmParser::RuleValues;
}

void avmParser::ValuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValues(this);
}

void avmParser::ValuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValues(this);
}


antlrcpp::Any avmParser::ValuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<avmVisitor*>(visitor))
    return parserVisitor->visitValues(this);
  else
    return visitor->visitChildren(this);
}

avmParser::ValuesContext* avmParser::values() {
  ValuesContext *_localctx = _tracker.createInstance<ValuesContext>(_ctx, getState());
  enterRule(_localctx, 12, avmParser::RuleValues);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    type();
    setState(61);
    match(avmParser::T__11);
    setState(62);
    argument();
    setState(63);
    match(avmParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

avmParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t avmParser::TypeContext::getRuleIndex() const {
  return avmParser::RuleType;
}

void avmParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void avmParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


antlrcpp::Any avmParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<avmVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

avmParser::TypeContext* avmParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 14, avmParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << avmParser::T__13)
      | (1ULL << avmParser::T__14)
      | (1ULL << avmParser::T__15)
      | (1ULL << avmParser::T__16)
      | (1ULL << avmParser::T__17))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

avmParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* avmParser::ArgumentContext::N() {
  return getToken(avmParser::N, 0);
}

tree::TerminalNode* avmParser::ArgumentContext::Z() {
  return getToken(avmParser::Z, 0);
}


size_t avmParser::ArgumentContext::getRuleIndex() const {
  return avmParser::RuleArgument;
}

void avmParser::ArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument(this);
}

void avmParser::ArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<avmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument(this);
}


antlrcpp::Any avmParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<avmVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

avmParser::ArgumentContext* avmParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 16, avmParser::RuleArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    _la = _input->LA(1);
    if (!(_la == avmParser::N

    || _la == avmParser::Z)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> avmParser::_decisionToDFA;
atn::PredictionContextCache avmParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN avmParser::_atn;
std::vector<uint16_t> avmParser::_serializedATN;

std::vector<std::string> avmParser::_ruleNames = {
  "prog", "line", "comment", "endofread", "instruction", "opcode", "values", 
  "type", "argument"
};

std::vector<std::string> avmParser::_literalNames = {
  "", "'push'", "'pop'", "'dump'", "'assert'", "'add'", "'sub'", "'mul'", 
  "'div'", "'mod'", "'print'", "'exit'", "'('", "')'", "'int8'", "'int16'", 
  "'int32'", "'float'", "'double'", "' '"
};

std::vector<std::string> avmParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "SP", "N", "Z", "COMMENT", "EOL", "ENDOFREAD", "TAB"
};

dfa::Vocabulary avmParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> avmParser::_tokenNames;

avmParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x1b, 0x48, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x7, 
    0x2, 0x16, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x19, 0xb, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x5, 0x3, 0x1e, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x23, 0xa, 0x3, 0x3, 0x3, 0x5, 0x3, 0x26, 0xa, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x29, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2d, 0xa, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x39, 0xa, 0x6, 0x5, 0x6, 0x3b, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x2, 0x2, 
    0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x2, 0x5, 0x3, 0x2, 
    0x3, 0xd, 0x3, 0x2, 0x10, 0x14, 0x3, 0x2, 0x16, 0x17, 0x2, 0x48, 0x2, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x30, 0x3, 0x2, 0x2, 0x2, 0xa, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x3c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x43, 0x3, 0x2, 0x2, 0x2, 0x12, 0x45, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x16, 0x5, 0x4, 0x3, 0x2, 0x15, 0x14, 0x3, 0x2, 0x2, 0x2, 0x16, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x19, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x1b, 0x7, 0x2, 0x2, 0x3, 0x1b, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x1e, 0x7, 0x1b, 0x2, 0x2, 0x1d, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0x2d, 0x5, 0x6, 0x4, 0x2, 0x20, 0x22, 0x5, 0xa, 0x6, 0x2, 0x21, 0x23, 
    0x7, 0x15, 0x2, 0x2, 0x22, 0x21, 0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0x23, 0x25, 0x3, 0x2, 0x2, 0x2, 0x24, 0x26, 0x5, 0x6, 
    0x4, 0x2, 0x25, 0x24, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x28, 0x3, 0x2, 0x2, 0x2, 0x27, 0x29, 0x7, 0x19, 0x2, 0x2, 
    0x28, 0x27, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2d, 0x5, 0x8, 0x5, 0x2, 0x2b, 0x2d, 
    0x7, 0x19, 0x2, 0x2, 0x2c, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0x2d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x18, 0x2, 
    0x2, 0x2f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x1a, 0x2, 0x2, 
    0x31, 0x9, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x5, 0xc, 0x7, 0x2, 0x33, 
    0x34, 0x7, 0x15, 0x2, 0x2, 0x34, 0x35, 0x5, 0xe, 0x8, 0x2, 0x35, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x36, 0x38, 0x5, 0xc, 0x7, 0x2, 0x37, 0x39, 0x7, 
    0x19, 0x2, 0x2, 0x38, 0x37, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3b, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3d, 0x9, 0x2, 0x2, 0x2, 0x3d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x3f, 0x5, 0x10, 0x9, 0x2, 0x3f, 0x40, 0x7, 0xe, 0x2, 0x2, 0x40, 0x41, 
    0x5, 0x12, 0xa, 0x2, 0x41, 0x42, 0x7, 0xf, 0x2, 0x2, 0x42, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x44, 0x9, 0x3, 0x2, 0x2, 0x44, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x46, 0x9, 0x4, 0x2, 0x2, 0x46, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x17, 0x1d, 0x22, 0x25, 0x28, 0x2c, 0x38, 0x3a, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

avmParser::Initializer avmParser::_init;
