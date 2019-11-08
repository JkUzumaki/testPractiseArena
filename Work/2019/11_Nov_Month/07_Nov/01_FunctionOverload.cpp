#include<iostream>

void foo(int a = 1, char b = 'c'){
	std::cout << "(int a, char b)\n";
}

void foo(char a , int b){
	std::cout << "(char a, int b)\n";
}

/*void foo(){
	std::cout << "foo()\n";
}*/

int main()
{
	foo();
	return 0;
}
