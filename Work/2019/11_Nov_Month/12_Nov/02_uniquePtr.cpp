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
	std::unique_ptr<MyClass> ptr1 (new MyClass());
	std::unique_ptr<MyClass> ptr2 (new MyClass());

	ptr1->sayHello();
	ptr2->sayHello();

	ptr2 = std::move(ptr1);
	ptr2->sayHello();

	return 0;
}
