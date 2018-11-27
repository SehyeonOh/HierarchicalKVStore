#pragma once
#include "Hot.h"

template <class Heat>
class Hash : public Heat{
  public:
    virtual void Put(void);
    virtual void Get(void);

  private:
};
