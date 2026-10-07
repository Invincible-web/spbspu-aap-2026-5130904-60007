#include <iostream>

int main()
{
  int current { 0 };
  int previous { 0 };
  std::size_t count { 0 };
  std::size_t count_num { 0 };
  bool eof { false };

  while (eof != true) // (!eof)
  {
    std::cin >> current;
    if (!std::cin)
      {
        std::cerr << "Incorrect input" << '\n';
        std::cin.clear();
        return 1;
      }
    // остаётся good a
    if (current == 0)
    {
      eof = true;
      continue;
    }
    ++count_num;
    if (count_num != 1)
      if ((current % previous) == 0)
      {
        ++count;
      }
    previous = current;
  }

  if (count_num <= 1)
  {
    std::cerr << "Not enough data" << '\n';
    return 2;
  }
  std::cout << count << '\n';
  return 0;
}
