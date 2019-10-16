#include<iostream>

int foo(char s[]){
	int n = 0;
	while(*(s+n) != '\0'){
		n++;
	}
	return n;
}

int main()
{
	int test = foo("Hello World!");
	std::cout << test << "\n";
	return 0;
}
