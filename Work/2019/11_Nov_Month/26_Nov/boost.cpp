#include<iostream>
#include<boost/thread.hpp>
#include<boost/chrono.hpp> 

//Wait function
void wait(int seconds) 
{
	boost::this_thread::sleep_for(boost::chrono::seconds{seconds}); 
}   

//Thread fn
void thread() 
{ 
  for(int i=0; i<10;++i)
  { 
	wait(2);
	std::cout << i << " ";
  }
}

int main()
{
	boost::thread t{thread};
	t.join(); 
	return 0;
}
