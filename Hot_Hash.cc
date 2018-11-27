#include "Hash.h"

template <> void Hash<Hot>::Put(void){
  std::cout<< "Hash<Hot>Put" << std::endl;
}
template <> void Hash<Hot>::Get(void){
  std::cout<< "Hash<Hot>Get" << std::endl;
}

