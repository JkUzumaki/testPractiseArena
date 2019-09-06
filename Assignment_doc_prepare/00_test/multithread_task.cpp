#include<iostream>
#include<thread>
#include<unistd.h>

//int g = 0;

int fn(int &g){
	//static int g = 0;
	int i = 0;
	while(i != 10000){
		g++;
		i++;
	}
	return g;
}

int main()
{
	int g = 0;
 	g =  std::thread t1(fn, g);
	//std::thread t2(fn);
	//std::thread t3(fn);

	std::cout << "The value of g : " << g << std::endl;

	t1.join();
	//t2.join();
	//t3.join();
	
	std::cout << "The value of g : " << g << std::endl;
	return 0;
}
