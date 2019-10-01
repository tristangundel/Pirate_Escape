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
  void setRequiredTool(std::string);
  void setSuccessMessage(std::string);
  std::string getSuccessMessage();
  void setRetrievedTool(Tool *tool);
  std::string getRequiredTool();
  Tool* getRetrievedTool();
  virtual void spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items);
  virtual ~ActionSpace();
};
#endif
