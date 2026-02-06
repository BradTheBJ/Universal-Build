#include "addFlag.hpp"
#include "helpers/getContentOfParens.hpp"
#include <iostream>

void addFlag(std::vector<std::string> &flags, Token &token) {
	std::string content = getContentOfParens(token.value);
	size_t pos = 0;
	while (pos < content.size()) {
		while (pos < content.size() && std::isspace(content[pos])) {
			pos++;
		}
		if (pos >= content.size()) {
			break;
		}
		size_t next = content.find(' ', pos);
		if (next == std::string::npos) {
			next = content.size();
		}
		flags.push_back(content.substr(pos, next - pos));
		pos = next;
	}
}
