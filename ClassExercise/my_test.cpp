#include <iostream>

class GrandP{
  public:
  void func(void){
    std::cout << "GrandP normal func" << std::endl;
  }
  virtual void virfunc(void){
    std::cout << "GrandP virtual func" << std::endl;
  }
};

class Mother : public virtual GrandP{
  public:
    Mother(void){
    std::cout << "Mother normal constructor" << std::endl;
      a_ = 0;
    }
  void func(void){
    std::cout << "Mother normal func" << std::endl;
  }
  virtual void virfunc(void){
    std::cout << "Mother virtual func" << std::endl;
  }
  void a(void){
    std::cout << "Mother a func" << std::endl;
    std::cout << a_ << std::endl;
  }
  virtual void F(void){}
  private:
    int a_;
};
class Father : public virtual GrandP{
  public:
    Father(void){
    std::cout << "Father normal constructor" << std::endl;
      a_ = 1;
    }
  void func(void){
    std::cout << "Father normal func" << std::endl;
  }
  virtual void virfunc(void){
    std::cout << "Father virtual func" << std::endl;
  }
  void a(void){
    std::cout << "Father a func" << std::endl;
    std::cout << a_ << std::endl;
  }
  virtual void F(void){}
  private:
    int a_;
};

class Child : public Mother, public Father{
  public:
    Child(void){
    std::cout << "Child normal constructor" << std::endl;
    }

  void func(void){
    std::cout << "Child normal func" << std::endl;
  }
  virtual void virfunc(void){
    std::cout << "Child virtual func" << std::endl;
  }
  void F(void){
    std::cout << "Child F " << std::endl;
  }
};
template <class T>
class Baby : public T{
  public:
    Baby(void){
    std::cout << "Baby normal constructor" << std::endl;
    }

  void func(void){
    std::cout << "Baby normal func" << std::endl;
  }
  virtual void virfunc(void){
    std::cout << "Baby virtual func" << std::endl;
  }
  virtual void F(void){
    std::cout << "Baby F " << std::endl;
    T::a();
  }
};

int main(){
  std::cout << "GrandP Creation\n\n";
  GrandP ** person = new GrandP*[4];
  person[0] = new GrandP;
  person[1] = new Mother;
  person[2] = new Father;
  person[3] = new Child;
  std::cout << "GrandP person\n\n";
  for(int i = 0; i < 4; i++){
    person[i]->func();
    person[i]->virfunc();
  }
  std::cout << "Mother Creation\n\n";
  Mother ** Mperson = new Mother*[4];
  Mperson[0] = new Mother;
  Mperson[1] = new Child;
  Mperson[2] = new Baby<Mother>;
//  Mperson[3] = new Baby<Father>;
  std::cout << "Mother Mperson\n\n";
  for(int i = 0; i < 4; i++){
    if(i==3)continue;
    Mperson[i]->func();
    Mperson[i]->virfunc();
    Mperson[i]->a();
    if(i==2)Mperson[i]->F();
  }
  std::cout << "Father Creation\n\n";
  Father ** Fperson = new Father*[4];
  Fperson[0] = new Father;
  Fperson[1] = new Child;
//  Fperson[2] = new Baby<Mother>;
  Fperson[3] = new Baby<Father>;
  std::cout << "Father Fperson\n\n";
  for(int i = 0; i < 4; i++){
    if(i==2)continue;
    Fperson[i]->func();
    Fperson[i]->virfunc();
    Fperson[i]->a();
    if(i==3)Fperson[i]->F();
  }
  return 0;
}
