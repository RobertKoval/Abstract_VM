#include <iostream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "gen/avmLexer.h"
#include "gen/avmParser.h"
#include "includes/AbstractVM.hpp"

void readFromStdIn(AbstractVM &app) {
	std::stringstream inReader;
	std::string       tmp;
	while (1) {
		std::getline(std::cin, tmp);
		if (tmp[0] == ';' && tmp[1] == ';') {
			break;
		}
		inReader << tmp << std::endl;
		tmp = "";
	}
	antlr4::ANTLRInputStream  input(inReader);
	avmLexer                  lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	avmParser                 parser(&tokens);
	avmParser::ProgContext    *tree = parser.prog();

	if ((parser.getNumberOfSyntaxErrors() && !app.isDebugMode()) || (lexer.getNumberOfSyntaxErrors() && !app.isDebugMode())) {
		throw std::runtime_error("App terminated due to syntax errors!");
	}
	else {app.calculate(tree);}
}

void readFromFile(AbstractVM &app, char *filename) {
	std::ifstream stream;
	stream.open(filename, std::fstream::in);
	if (!stream) {
		throw std::invalid_argument("Error! Can't open file!");
	}

	antlr4::ANTLRInputStream  input(stream);
	avmLexer                  lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	avmParser                 parser(&tokens);
	avmParser::ProgContext    *tree = parser.prog();

	if ((parser.getNumberOfSyntaxErrors() && !app.isDebugMode()) || (lexer.getNumberOfSyntaxErrors() && !app.isDebugMode())) {
		throw std::runtime_error("App terminated due to syntax errors!");
	}
	else {app.calculate(tree);}
}

int main(int ac, char **av) {
	AbstractVM app;
	try {
		if (ac == 1) {readFromStdIn(app);}
		else if (ac == 2) {
			std::string a(av[1]);
			if (a == "-d" || a == "-debug") {
				app.setDebugMode(true);
				readFromStdIn(app);
			}
			else {readFromFile(app, av[1]);}
		}
		else if (ac == 3) {
			std::string a(av[1]);
			std::string b(av[2]);

			if (a == "-d" || a == "-debug") {
				app.setDebugMode(true);
				readFromFile(app, av[2]);
			}
			else if (b == "-d" || a == "-debug") {
				app.setDebugMode(true);
				readFromFile(app, av[1]);
			}
			else {
				throw std::invalid_argument(
					"Error! Invalid arguments!\n./avm [-d] [filename.avm]");
			}
		}
		else {
			throw std::invalid_argument(
				"Error! Invalid arguments!\n./avm [-d] [filename.avm]");
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

/**
 * https://www.h-schmidt.net/FloatConverter/IEEE754.html - float converting checker
 */