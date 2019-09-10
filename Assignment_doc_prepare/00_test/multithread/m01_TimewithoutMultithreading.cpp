#include <iostream>
#include <chrono>

void fn1()
{
	int i = 0;
	while(i != 100000000){
		i++;
	}
	std::cout << "Hi 1\n";
}

void fn2()
{
	int i = 0;
	while(i != 100000000){
		i++;
	}
	std::cout << "Hi 2\n";
}


void fn3()
{
	int i = 0;
	while(i != 100000000){
		i++;
	}
	std::cout << "Hi 3\n";
}

int main()
{
	auto start = std::chrono::system_clock::now();

	fn1();
	fn2();
	fn3();

	auto end = std::chrono::system_clock::now();

	auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	std::cout << "The execution time is " << diff.count() << " microsec " << std::endl;
	return 0;
}
