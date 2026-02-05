#include <format>
#include <iostream>
#include "include/lexer.hpp"

int main() {
    lex();
    std::cout << std::format("Hello, World!\n");
    std::cout << std::format("Tokens found: {}\n", lexResult.size() + 1);
}
