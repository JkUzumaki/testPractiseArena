#include <iostream>
#include <future>
#include <thread>

int fun(int a){
    
    std::thread::id th = std::this_thread::get_id();
    std::cout << "The fun thread id : " << th << std::endl;
    a = a+1;
    return a;
}

int main()
{
        std::thread::id th = std::this_thread::get_id();
        std::cout << "The main thread id : " << th << std::endl;
	int var = 20;

	std::future<int> val = std::async(fun, var);
	int v1 = val.get();

	std::cout << "The val " << v1 << std::endl;
	return 0;
}
