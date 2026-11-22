#include <iostream>
#include <new>

namespace vanyugin
{
  constexpr int err_input = 1;
  constexpr int err_memory = 2;

  char* inputString(size_t bufer, char* input_string, size_t& i, bool& check);
  size_t finalSizeString(const char* string, size_t size_string);
  void deleteSpace(const char* string, size_t size_string, size_t size_final_string, char* final_string);
}

int main()
{
  char* string = nullptr;
  constexpr size_t bufer = 1024;
  size_t size_string{0}, size_final_string{0};
  char* const input_string = new (std::nothrow) char[bufer];
  bool check = false;

  if (input_string == nullptr)
  {
    delete[] input_string;
    std::cerr << "Unable to allocate dynamic memory\n";
    return vanyugin::err_memory;
  }

  string = vanyugin::inputString(bufer, input_string, size_string, check);

  if (size_string == 0)
  {
    delete[] input_string;
    std::cerr << "No input\n";
    return vanyugin::err_input;
  }

  if (check)
  {
    delete[] input_string;
    std::cerr << "Not enough memory\n";
    return vanyugin::err_memory;
  }

  size_final_string = vanyugin::finalSizeString(string, size_string);
  char* const final_string = new (std::nothrow) char[size_final_string];

  vanyugin::deleteSpace(string, size_string, size_final_string, final_string);

  if (final_string == nullptr)
  {
    delete[] input_string;
    delete[] final_string;
    std::cerr << "Out of memory\n";
    return vanyugin::err_memory;
  }

  std::cout << final_string << "\n";
  delete[] input_string;
  delete[] final_string;
  return 0;
}

namespace vanyugin
{
  char* inputString(size_t bufer, char* input_string, size_t& i, bool& check)
  {
    if (input_string == nullptr)
    {
      return nullptr;
    }

    char token = '0';

    while (std::cin.get(token))
    {
      if (token == '\n')
      {
        break;
      }
      else if (i + 1 >= bufer)
      {
        check = true;
        break;
      }

      input_string[i] = token;
      i++;
    }
    return input_string;
  }

  size_t finalSizeString(const char* string, size_t size_string)
  {
    if (string == nullptr)
    {
      return 0;
    }

    size_t count{0}, i{0};
    while (i < size_string)
    {
      if (string[i] == ' ' && i == 0)
      {
        i++;
        count++;
        for (; i < size_string; i++)
        {
          if (string[i] == ' ')
          {
            count++;
          }
          else
          {
            break;
          }
        }
      }

      if (string[i] == ' ')
      {
        for (; i < size_string; i++)
        {
          if (string[i] == ' ')
          {
            count++;
          }
          else
          {
            count--;
            break;
          }
        }
      }
      i++;
    }

    return size_string - count + 1;
  }

  void deleteSpace(const char* string, size_t size_string, size_t size_final_string, char* final_string)
  {
    if (string == nullptr || final_string == nullptr)
    {
      return;
    }

    size_t i{0}, j{0};
    for (; i < size_string; i++)
    {
      if (string[i] != ' ')
      {
        final_string[j] = string[i];
        j++;
      }
      else if (j != 0 && j != size_final_string && final_string[j - 1] != ' ')
      {
        final_string[j] = string[i];
        j++;
      }
    }
    final_string[j] = '\0';
  }

}
