#pragma once
#include <vector>
#include <string>

enum class TokenType {
    ADD_FLAG,
    SET_COMPILER,
    DETECT_COMPILER,
    EXEC
};

struct Token {
    TokenType type;
    std::string value;
};

void lex();

extern std::vector<Token> lexResult;