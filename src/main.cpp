#include "include/lexer.hpp"
#include "include/parser.hpp"
#include <format>
#include <iostream>


int main() {
  lex();
  parse(lexResult);
  std::cout << std::format("Hello, World!\n");
  std::cout << std::format("Tokens found: {}\n", lexResult.size());
}
