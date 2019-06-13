#include <iostream>

struct C {
  int data;
  C() {
 std::cout<<"constructor \n";
}
  C(const C&) { std::cout << "A copy was made.\n"; }
};

C f() {
  return C();
}

int main() {
  std::cout << "Hello World!\n";
  C obj = f();
  return 0;
}
