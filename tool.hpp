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
