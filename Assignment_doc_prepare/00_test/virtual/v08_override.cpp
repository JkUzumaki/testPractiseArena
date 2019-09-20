#include <iostream>

struct A 
{ 
  virtual int foo() 
  {
    int x = 99; 
    std::cout << "x : " << x << std::endl;
    return x; 
  } 
}; 

struct B : public A 
{ 
  int foo() 
  {
    int x = 77; 
    std::cout << "x : " << x << std::endl;
    return x; 
  } 
}; 

int main(int argc, char** argv) 
{ 
  A* a = new B; 
  //B b;
  //A* a = &b;
  std::cout << a->foo() << std::endl;  // output 99

  return 0; 
}
