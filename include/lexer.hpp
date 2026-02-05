#pragma once
#include <vector>
#include <string>

enum class TokenType {
    ADD_FLAG,
    SET_COMPILER,
    EXEC,
    //UNKNOWN
    // TODO: Add more token types as needed and implement token UNKNOWN
};

struct Token {
    TokenType type;
    std::string value;
};

void lex();

extern std::vector<Token> lexResult;