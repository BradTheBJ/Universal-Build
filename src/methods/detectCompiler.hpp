#pragma once
#include <string>
#include "include/lexer.hpp"

std::string detectCompiler(const std::string& currentCompiler, Token& token, size_t& line);