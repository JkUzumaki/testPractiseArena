#include <iostream>
struct A 
{ 
  virtual int foo(int x = 99) 
  { 
    std::cout << "Inside A ";
    return x; 
  } 
}; 
struct B : public A 
{ 
  int foo(int x = 77) 
  { 
    std::cout << "Inside B ";
    return x; 
  } 
}; 

int main() 
{ 
  A* a = new B; 
  std::cout << a->foo() << std::endl;  // output 99
  return 0; 
}
