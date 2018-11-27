#pragma once
#include "Warm.h"
#include "Cold.h"

template <class Heat>
class BTree : public Heat{
  public:
    virtual void Put(void);
    virtual void Get(void);
  private:
};
