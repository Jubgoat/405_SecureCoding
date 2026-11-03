// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

 

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  std::cout << "Enter a value: ";

  std::string raw_input;
  std::cin >> raw_input;

  if (raw_input.size() > sizeof(user_input) - 1)
  {
      std::cout << "Warning: your input was " << raw_input.size()
          << " characters, but only " << (sizeof(user_input) - 1)
          << " characters are allowed. Your input will be truncated to fit safely."
          << std::endl;
  }

  size_t copy_length = std::min(raw_input.size(), sizeof(user_input) - 1);
  std::memcpy(user_input, raw_input.c_str(), copy_length);
  user_input[copy_length] = '\0';

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
