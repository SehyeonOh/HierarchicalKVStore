#include "BTree.h"

template <> void BTree<Cold>::Put(void){
  std::cout<< "BTree<Cold> Put" << std::endl;
}
template <> void BTree<Cold>::Get(void){
  std::cout<< "BTree<Cold> Get" << std::endl;
}

