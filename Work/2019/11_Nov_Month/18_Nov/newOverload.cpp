#include<iostream>

class Test
{
public:
	//void* operator new(size_t t) = delete;
	void operator delete(size_t t) = delete;
	void fn(){
		std::cout << "Test::fn\n";
	}
};
int main()
{
	Test *ptr = new Test();
	ptr->fn();
	delete ptr;
	return 0;
}
