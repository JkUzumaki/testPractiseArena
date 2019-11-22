#include<iostream>

class test{
public:
	static int data;
};
int test::data = 10;

int main()
{
	std::cout << "data: " << test::data << std::endl;
	return 0;
}
