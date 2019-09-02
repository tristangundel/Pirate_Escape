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
  Tool(std::string);
  std::string getToolName();
};

#endif
