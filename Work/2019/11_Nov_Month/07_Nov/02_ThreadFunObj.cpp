#include<iostream>
#include<thread>

class test
{
public:
	void operator()(int a)
	{
		std::cout << "test::operator() "<< a << "\n";
	}
};

int main()
{
	test t;
	std::thread th(t, 97);
	th.join();
	return 0;
}
