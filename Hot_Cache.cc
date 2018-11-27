#include "Cache.h"

template <> void Cache<Hot>::Put(void){
  std::cout<< "Cache<Hot>Put" << std::endl;
}
template <> void Cache<Hot>::Get(void){
  std::cout<< "Cache<Hot>Get" << std::endl;
}

