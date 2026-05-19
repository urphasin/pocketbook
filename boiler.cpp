#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  std::cout << std::setw(6) << 
  "Odd" << std::setw(6) << 
  "Even" << std:: endl;

  for (int i = 1; i <=29; i += 2) {
    if (i == 29) {
      std::cout << std::setw(6) << 
      i << std::endl;
      break;
    }
    std::cout << std::setw(6) << 
    i << std::setw(6) << 
    i + 1 << std:: endl;
  }

  int val = (3 - 5*8*8 + 8*8*8) * 5;
  std::cout << val << std::endl;

  return 0;
}