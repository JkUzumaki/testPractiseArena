#include<iostream>
#include<thread>

std::thread::id mt;

void fn(){
	mt = std::this_thread::get_id();
	std::cout << "The thread inside fn() id is " << mt << std::endl;
}

int main()
{
	mt = std::this_thread::get_id();
	std::cout << "The main thread id is " << mt << std::endl;
	fn();
	return 0;
}
