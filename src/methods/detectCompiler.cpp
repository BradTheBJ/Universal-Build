#include "detectCompiler.hpp"
#include "helpers/getContentOfParens.hpp"
#include <format>
#include <iostream>

std::string detectCompiler(const std::string &currentCompiler, Token &token, size_t &line) {
    std::string content = getContentOfParens(token.value);
    std::string compiler = currentCompiler; // start with what was passed

    if (content == "c") {
        if (std::system("gcc --version > /dev/null 2>&1") == 0) {
            compiler = "gcc";
      } else if (std::system("clang --version > /dev/null 2>&1") == 0) {
            compiler = "clang";
      } else {
            std::cerr << "\033[31m" << std::format("Could not detect C compiler at line {}\n", line) << "\033[0m";
            std::exit(1);
      }
    } else if (content == "cpp" || content == "c++" || content == "cxx") {
        if (std::system("g++ --version > /dev/null 2>&1") == 0) {
            compiler = "g++";
        } else if (std::system("clang++ --version > /dev/null 2>&1") == 0) {
            compiler = "clang++";
        } else {
            std::cerr << "\033[31m" << std::format("Could not detect C++ compiler at line {}\n", line) << "\033[0m";
            std::exit(1);
        }
    } else {
        std::cerr << "\033[31m" << std::format("Unknown language '{}' for detectCompiler at line {}\n", content, line) << "\033[0m";
        std::exit(1);
    }

    std::cout << "\033[32m" << std::format("Detected compiler: {}\n", compiler) << "\033[0m";
    return compiler;
}
