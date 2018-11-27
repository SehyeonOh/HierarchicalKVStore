#include <iostream>
#include "HieKV.h"


int main(){
  HieKV ** obj = new HieKV*[4];
  for(int i = 0; i < 4; i++){
    obj[i] = new HieKV(i);
    std::cout << "Put\n";
    obj[i]->Put();
    std::cout << "Get\n";
    obj[i]->Get();
  }
  return 0;
}
