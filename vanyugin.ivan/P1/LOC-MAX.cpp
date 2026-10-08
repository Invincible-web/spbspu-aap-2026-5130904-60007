#include <iostream>

#define ERROR_NOT_ENOUGH_DATA 2

int main() {
  const int INITAL_F_VALUE = 3;
  int a = {1}, b = {0}, c = {0}, r = {0}, count = {0}, f = {INITAL_F_VALUE};
  while (a != 0) {
    std::cin >> a;

    if (std::cin.fail()) {
      std::cerr << "Unexpected input\n";
      return 1;
    }

    if (a == 0) {
      if (count > f && b > c) {
        ++r;
      }
      break;
    }

    if (c == 0 && b != 0) {
      if (b > a) {
        ++r;
      }
    }

    if (b != 0 && c != 0) {
      if (a < b && c < b) {
        ++r;
      }
    }

    c = b;
    b = a;
    ++count;
  }

  if (count == 0) {
    std::cerr << "Not enough data\n";
    return ERROR_NOT_ENOUGH_DATA;
  } else if (count == 1) {
    std::cout << "Ответ:" << 0 << "\n";
  } else {
    std::cout << "Ответ:" << r << "\n";
  }
}
