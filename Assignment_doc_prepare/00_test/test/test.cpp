#include<iostream>

char* fn()
{
	char* str = "Hello";
	return str;
}

int main(){
	char* s = fn();
	std::cout << s << "\n";
}
