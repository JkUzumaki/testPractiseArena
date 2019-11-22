#include<iostream>

class Test
{
public:
	Test(){
		data1 = 0;
	//	data2 = 10;
	}
	int data1;
	static int data2;
	void fun1();
	static void fun2();
};

int Test::data2 = 99;

void Test::fun1()
{
	std::cout << "Test inside the fun1 function\n";
	std::cout << "Non static data: " << data1 << std::endl;
	data2 = data2 + 1;
	std::cout << "Static data : " << data2 << " Inside normal function" << std::endl;
}

void Test::fun2()
{
	std::cout << "Test inside the static fun2 function\n";
	data1 += 1;
	std::cout << "Non static data: " << data1 << std::endl;
	std::cout << "Static data : " << data2 << std::endl;
}

int main()
{
	Test obj;
	std::cout << "\n";
	obj.fun1();
	std::cout << "\n";
	obj.fun2();
	return 0;
}
