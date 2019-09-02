/*********************************************************************
** Program name: PirateEscape
** Author: Tristan Gundel
** Date: 12/04/2018
** Description: This file is one of 21 files that together form a
**              program with the capability of running a sinle player
**              pirate themed escape room game where the user will
**              move around the board picking up items and hints to
**              use to get out of the room.
*********************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include "inputValidation.hpp"

// Takes in a string input and returns true if it's a valid integer
bool validateNumber(std::string input)
{
  bool isNumber = true;
  for (size_t c = 0; c < input.length(); ++c)
  {
    if (!std::isdigit(input[c]))
    {
      return false;
    }
  }
  return isNumber;
}

// Takes in a string input and returns true if it's a valid integer
// within a lower and upper bound (inclusive)
bool validateInput(std::string input, int low, int high)
{
  bool isANumber = validateNumber(input);
  if(isANumber && low <= std::stoi(input) && high >= std::stoi(input))
  {
    return true;
  }
  else
  {
    std::cout << "That input was not valid, please try again" << std::endl;
    return false;
  }
}
