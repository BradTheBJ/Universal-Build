#include "getContentOfParens.hpp"

std::string getContentOfParens(const std::string &input) {
  std::string content;
  size_t start = input.find('(');
  size_t end = input.find(')', start);

  if (start != std::string::npos && end != std::string::npos && end > start) {
    content = input.substr(start + 1, end - start - 1);
  }

  return content;
}