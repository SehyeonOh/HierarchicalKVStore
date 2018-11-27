#include "BTree.h"

template <> void BTree<Warm>::Put(void){
  std::cout<< "BTree<Warm>Put" << std::endl;
}
template <> void BTree<Warm>::Get(void){
  std::cout<< "BTree<Warm>Get" << std::endl;
}

