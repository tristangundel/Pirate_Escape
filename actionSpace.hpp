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
#ifndef ACTION_SPACE_HPP
#define ACTION_SPACE_HPP
#include "space.hpp"
#include <vector>
#include <string>

class ActionSpace : public Space
{
private:
  std::string requiredTool;
  std::string successMessage;
  Tool *retrievedTool;
public:
  ActionSpace();
  ActionSpace(int);
  void printList(std::vector<Tool*>tools);
  void setSuccessMessage(std::string message);
  std::string getSuccessMessage();
  void setRequiredTool(std::string tool);
  std::string getRequiredTool();
  void setRetrievedTool(Tool* tool);
  Tool* getRetrievedTool();
  virtual void spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items);
  virtual ~ActionSpace();
};
#endif
