#include <iostream>
#include <string>
#include <vector>

int main() {
  for (std::string line; std::getline(std::cin, line);) {
    std::cout << line << std::endl;
  }
  return 0;
}