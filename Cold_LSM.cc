#include "LSM.h"

template <> void LSM<Cold>::Put(void){
  std::cout<< "LSM<Cold>Put" << std::endl;
}
template <> void LSM<Cold>::Get(void){
  std::cout<< "LSM<Cold>Get" << std::endl;
}

