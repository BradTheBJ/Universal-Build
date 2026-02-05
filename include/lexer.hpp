#pragma once
#include <vector>
#include <string>

enum class TokenType {
    ADD_FLAG,
    SET_COMPILER,
    EXEC,
    // TODO: Add more token types as needed
};

struct Token {
    TokenType type;
    std::string value;
};

void lex();

extern std::vector<Token> lexResult;