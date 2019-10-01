#ifndef PARROTSPACE_HPP
#define PARROTSPACE_HPP
#include "actionSpace.hpp"
#include <vector>
#include <string>

class ParrotSpace : public ActionSpace
{
  public:
    ParrotSpace();
    virtual void spaceFunction(std::vector<Tool*>& hints, std::vector<Tool*>& items);
    virtual ~ParrotSpace();
};

#endif
