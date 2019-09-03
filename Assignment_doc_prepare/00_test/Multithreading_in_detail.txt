Thread can be created in the following mechanism:
	1. Using function pointer
	2. Using functor
	3. Using lambda function

Using function pointer:
-----------------------
	A function pointer is a variable that stores the address of the function that can be later called through that function pointer.
	CODE:
		void foo(param) 
		{ 
			// Do something 
		} 
		// The parameters to the function are put after the comma 
		std::thread thread_obj(foo, params);

	// Call back mechanism
	#include<iostream>
	void fn1()
	{
		std::cout << "fun A\n";
	}
	void fn2(void (*ptr)())
	{
		(*ptr)();   //call back is happening
	}
	int main()
	{
		void (*ptr)() = &fn1;	// syntax for function pointer: void (*ptr)() = function_address;
		fn2(ptr);
		return 0;
	}
	
Using functor:
--------------
	functor is a object of a class.
	Eg:
	CODE:
		// Define the class of function object 
		class fn_object_class { 
			// Overload () operator 
			void operator()(params) 
			{ 
				// Do Something 
			} 
		} 
		// Create thread object 
		std::thread thread_object(fn_class_object(), params) 
	////////////////////////////////////////////////////////
		#include<iostream>
		#include<thread>
		class base
		{
		public:
			void operator()() {
				std::cout << "Welcome to overloadded () function\n";        
			}
			 void fn()
			 {
				std::cout << "Welcome to fn in base\n";
			 }
		};
		int main()
		{
			base b;
			std::thread t2((base()));
			std::thread t1(b);
			t1.join();
			return 0;
		}
	///////////////////////////////////////////////////////
	//Deadlock program example program
	#include <iostream>
	#include <thread>
	#include <mutex>

	std::mutex mt;
	void fn(int a){
		if(a==1){
			std::cout << "thread 1 is using the resource\n";
		}else if(a == 2){
			std::cout << "thread 2 is using the resource\n";
		}
		mt.lock();
		std::cout << "Inside fn call\n";
		//mt.unlock();
	}

	int main()
	{
		std::thread t1(fn,1);
		std::thread t2(fn,2);
		t1.join();
		t2.join();
		return 0;
	}
	
//---------------------------------------------------------------------------------------------------------
