#ifndef ACTION_SPACE_HPP
#define ACTION_SPACE_HPP
#include "space.hpp"
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
  void setRequiredTool(std::string);
  void setSuccessMessage(std::string);
  void setRetrievedTool(Tool *tool);
  std::string getRequiredTool();
  virtual void spaceFunction(Queue *hints, Queue *items);
};
#endif
