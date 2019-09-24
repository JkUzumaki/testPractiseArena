#include<iostream>
#include<string>
using namespace std;

struct a{
	virtual ~a(){
		std::cout << "~a()\n";
	}
};

struct b: public a{
	~b(){
		std::cout << "~b throw 1\n";
		throw 1;
	}
};

bool c(){
	a *d = new b;
	try{
		delete d;
	}
	catch(int e){
		std::cout << "catch e\n";
		return e;
	}
	return false;
}

int main()
{
	bool test  = c();
	std::cout << "test : " << test << std::endl;
	return 0;
}
