#include<iostream>
#include<thread>
#include<pthread.h>
#include<mutex>

std::mutex mtx;

void f1(int a){
	sched_param sch;
	int policy;
	pthread_getschedparam(pthread_self(), &policy, &sch);
	std::lock_guard<std::mutex> lck(mtx);
	std::cout << "In f1 function "<< a <<"\n";	
}


int main()
{
	std::thread t3(f1, 3);
	std::thread t4(f1, 4);
	std::thread t5(f1, 5);
	std::thread t2(f1, 2);
	std::thread t1(f1, 1);
	
	sched_param s;
	int policy;
	pthread_getschedparam(t5.native_handle(), &policy, &s);
	s.sched_priority = 10;
	//Error message 	
	/*
	if(pthread_setschedparam(t1.native_handle(), SCHED_FIFO, &s)){
		std::cout << "Error in setschemparam\n";
	}
	*/	
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t1.join();
	return 0;	
}
