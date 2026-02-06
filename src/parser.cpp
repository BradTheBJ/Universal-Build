#include "include/parser.hpp"
#include "methods/addFlag.hpp"
#include "methods/detectCompiler.hpp"
#include "methods/exec.hpp"
#include "methods/setCompiler.hpp"
#include <format>
#include <iostream>

std::vector<std::string> flags;
std::string compiler;
std::pair<std::string, std::vector<std::string>> execCommand;

void parse(const std::vector<Token> &tokens) {
  size_t line = 1;
  for (const auto &token : tokens) {
    switch (token.type) {
    case TokenType::SET_COMPILER: {
      compiler = setCompiler(const_cast<Token &>(token));
      break;
    }
    case TokenType::ADD_FLAG: {
      addFlag(flags, const_cast<Token &>(token));
      break;
    }
    case TokenType::EXEC: {
      exec(compiler, flags, line);
      break;
    }
    case TokenType::DETECT_COMPILER: {
      compiler = detectCompiler(compiler, const_cast<Token &>(token), line);
      break;
    }
    default: {
      std::cerr << "\033[31m"
                << std::format("Unknown token '{}' at line {}\n", token.value,
                               line)
                << "\033[0m";
      std::exit(1);
    }
    }
    line++;
  }
}
