#include<iostream>
#include<string>
#include<memory>
#include<sstream>

class MyClass
{
	static int count;
	std::string name;
public:
	MyClass(){
		std::ostringstream stringStream(std::ostringstream::ate);
		stringStream << 'Object';
		stringStream << ++count;
		name = stringStream.str();
		std::cout << "\nMyClass default constructor " << name << "\n";
	}
	~MyClass(){
		std::cout << "\nMyClass destructor " << name << "\n";
	}
	MyClass(const MyClass& ref){
		std::cout << "\nMyClass copy constructor \n";
	}
	MyClass operator=(const MyClass &ref){
		std::cout << "\nMyClass assignment operator" << name << "\n";
	}
	void sayHello(){
		std::cout << "Hello from MyClass " << name << std::endl;
	}
};

int MyClass::count = 0;

int main()
{
	std::shared_ptr<MyClass> ptr1 (new MyClass());
	ptr1->sayHello();
	std::cout << "\nShared pointer count : " << ptr1.use_count() << "\n";
	{
		std::shared_ptr<MyClass> ptr2 (ptr1);
		ptr2->sayHello();
		std::cout << "\nShared pointer count : " << ptr2.use_count() << "\n";
	}
	std::cout << "\nShared pointer count : " << ptr1.use_count() << "\n";
	std::shared_ptr<MyClass> ptr4 (ptr1);
	//delete ptr1;
	ptr1.reset();
	std::shared_ptr<MyClass> ptr3 = ptr4;
	ptr3->sayHello();
	std::cout << "\nShared pointer count : " << ptr3.use_count() << "\n";
	return 0;
}
