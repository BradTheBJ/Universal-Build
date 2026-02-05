#pragma once
#include <vector>
#include <string>

enum class TokenType {
    EOF_TOKEN,
    ADD_FLAG,
    SET_COMPILER,
    EXEC,
    UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

void lex();

extern std::vector<Token> lexResult;