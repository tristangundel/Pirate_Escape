/*********************************************************************
** Program name: PirateEscape
** Author: Tristan Gundel
** Date: 09/19/2019
** Description: This file is one of 23 files that together form a
**              program with the capability of running a single player
**              pirate themed escape room game where the user will
**              move around the board picking up items and hints to
**              use to get out of the room.
*********************************************************************/
#ifndef TOOL_HPP
#define TOOL_HPP
#include <string>

class Tool
{
private:
  std::string toolName;
  bool isItem;
public:
  Tool();
  std::string getToolName();
  void setToolName(std::string);
  void setIsItem(bool);
  bool getIsItem();
};

#endif
