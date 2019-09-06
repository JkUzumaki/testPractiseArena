#include<iostream>
#include<thread>

int fn(int a){
	a+=1;
	return a;
}

int main()
{
	int v1 = 10;
	int v2 = 0;
	std::thread t1([&v2, v1]{v2 = fn(v1);});
	t1.join();
	std::cout << "The v2 " << v2 << std::endl;
	return 0;
}
