#pragma once
#include "Hot.h"
#include "Warm.h"
#include "Cold.h"
#include "Cache.h"
#include "Hash.h"
#include "BTree.h"
#include "LSM.h"

class HieKV{
  public:
    HieKV(int n){
      if(n == 0){
        std::cout << "Cache - B-tree - LSM" << std::endl;
        hot = new Cache<Hot>;
        warm = new BTree<Warm>;
        cold = new LSM<Cold>;
      }
      if(n == 1){
        std::cout << "Cache - LSM - B-tree"<< std::endl;
        hot = new Cache<Hot>;
        warm = new LSM<Warm>;
        cold = new BTree<Cold>;

      }
      if(n == 2){
        std::cout << "Hash - B-tree - LSM"<< std::endl;
        //Hash - B-tree - LSM
        hot = new Hash<Hot>;
        warm = new BTree<Warm>;
        cold = new LSM<Cold>;

      }
      if(n == 3){
        std::cout << "Hash - LSM - B-tree"<< std::endl;
        //Hash - LSM - B-tree
        hot = new Hash<Hot>;
        warm = new LSM<Warm>;
        cold = new BTree<Cold>;

      }
    }
  //TODO:Need to set parameter and return type
  void Put(void){
    hot->Put();
    BackgroundPut();
    //HotPut(...)
    //if(eviction){
    //  Threadpool(BackgroundPut(evicted));
    //}
  }

  //TODO:Need to set parameter and return type
  void Get(void){
    hot->Get();
    warm->Get();
    cold->Get();
    //HotGet(...);
    //if(NotFound){
    //  WarmGet(...);
    //  if(NotFound){
    //    ColdGet(...);
    //  }
    //}
  }

  //TODO:Need to set parameter and return type
  void BackgroundPut(void){
    warm->Put();
    cold->Put();
    //WarmPut(...);
    //if(eviction){
    //  ColdPut(...);
    //}
  }
  private:
    Hot* hot;
    Warm* warm;
    Cold* cold;
};
