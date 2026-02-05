#include "include/lexer.hpp"
#include <fstream>
#include <stdexcept>
#include <format>
#include <iostream>

std::vector<Token> lexResult;

void lex() {
    std::ifstream file("build.ub");
    if (file.fail()) {
        // The wierd escape codes are for coloring the output red in terminals that support it
        std::cout << "\033[31m" << std::format("Could not open build.ub for reading\n") << "\033[0m";
        std::exit(1);
    }

    std::string buffer;
    char c;
    while(file.get(c)) {
        if (buffer == "setCompiler") {
            Token token;
            token.type = TokenType::SET_COMPILER;
            token.value = buffer;
            lexResult.push_back(token);
            buffer.clear();
        } else if (buffer == "addFlag") {
            Token token;
            token.type = TokenType::ADD_FLAG;
            token.value = buffer;
            lexResult.push_back(token);
            buffer.clear();
        } else if (buffer == "exec") {
            Token token;
            token.type = TokenType::EXEC;
            token.value = buffer;
            lexResult.push_back(token);
            buffer.clear();
        } else {
            buffer += c;
        }
    }
}
