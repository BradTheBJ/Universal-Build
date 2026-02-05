#include <format>
#include <iostream>
#include "include/lexer.hpp"
#include "include/parser.hpp"

int main() {
    lex();
    parse(lexResult);    
    std::cout << std::format("Hello, World!\n");
    std::cout << std::format("Tokens found: {}\n", lexResult.size());
}
