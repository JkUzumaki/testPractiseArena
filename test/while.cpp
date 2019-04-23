#include<iostream>

void foo()
{
	int v = 0;
	while(1){
		while( v == 0);
		std::cout << "\ninside while 1\n";
	}
}

int main()
{
	foo();
	return 0;
}
