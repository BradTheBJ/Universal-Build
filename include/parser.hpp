#pragma once
#include "lexer.hpp"
#include <utility>

void parse(const std::vector<Token>& tokens);
extern std::vector<std::string> flags;
extern std::string compiler;
extern std::pair<std::string, std::vector<std::string>> execCommand;