#include "include/lexer.hpp"
#include <fstream>
#include <iostream>
#include <format>
#include <cctype>

std::vector<Token> lexResult;

void lex() {
	std::ifstream file("build.ub");
	if (file.fail()) {
		std::cout << "\033[31m" << std::format("Could not open build.ub for reading\n") << "\033[0m";
		std::exit(1);
	}

	std::string buffer;
	char c;
	while (file.get(c)) {
		if (buffer.empty() && std::isspace(c)) {
			continue;
		}

		if (c == '#') {
			while (file.get(c) && c != '\n') {}
			buffer.clear();
			continue;
		}

		buffer += c;

		if (c == ')') {
			Token token;
			if (buffer.starts_with("setCompiler")) {
				token.type = TokenType::SET_COMPILER;
			} else if (buffer.starts_with("addFlag")) {
				token.type = TokenType::ADD_FLAG;
			} else if (buffer.starts_with("exec")) {
				token.type = TokenType::EXEC;
			} else if (buffer.starts_with("detectCompiler")) {
				token.type = TokenType::DETECT_COMPILER;
			} else {
				buffer.clear();
				continue;
			}

			token.value = buffer;
			lexResult.push_back(token);
			buffer.clear();
		}
	}
}
