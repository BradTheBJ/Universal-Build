#include "include/parser.hpp"
#include "helpers/getContentOfParens.hpp"
#include <iostream>
#include <format>

std::vector<std::string> flags;
std::string compiler;
std::pair<std::string, std::vector<std::string>> execCommand;

void parse(const std::vector<Token> &tokens) {
	for (const auto &token : tokens) {
		switch (token.type) {
		case TokenType::SET_COMPILER: {
			compiler = getContentOfParens(token.value);
			break;
		}
		case TokenType::ADD_FLAG: {
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
			break;
		}
		case TokenType::EXEC: {
            if (!compiler.empty()) {
                std::string fullCommand = compiler;
                for (const auto &f : flags) {
                    fullCommand += " " + f;
                }
                std::system(fullCommand.c_str());
            } else {
                std::cout << "\033[31m" << std::format("No compiler set for exec command\n") << "\033[0m";
                std::exit(1);
            }
            flags.clear();
            break;
        }
		}
	}
}
