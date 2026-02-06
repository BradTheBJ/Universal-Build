#include "setCompiler.hpp"
#include "helpers/getContentOfParens.hpp"

std::string setCompiler(Token &token) {
	return getContentOfParens(token.value);
}
