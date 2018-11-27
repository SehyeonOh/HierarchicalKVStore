#include "LSM.h"

template <> void LSM<Warm>::Put(void){
  std::cout<< "LSM<Warm>Put" << std::endl;
}
template <> void LSM<Warm>::Get(void){
  std::cout<< "LSM<Warm>Get" << std::endl;
}

