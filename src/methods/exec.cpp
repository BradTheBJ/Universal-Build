#include "exec.hpp"
#include <cstdlib>
#include <format>
#include <iostream>


void exec(const std::string &compiler, std::vector<std::string> &flags, size_t &line) {
	if (!compiler.empty()) {
		std::string fullCommand = compiler;
		for (const auto &f : flags) {
			fullCommand += " " + f;
		}
		std::system(fullCommand.c_str());
	} else {
		std::cerr << "\033[31m" << std::format("No compiler set for exec command at line {}\n", line) << "\033[0m";
		std::exit(1);
	}
	flags.clear();
}
