#include<iostream>
#include<memory>
#include<string>
#include<sstream>

class C;

class A{
private:
	//std::shared_ptr<C> ptr;
	std::weak_ptr<C> ptr;
public:
	A(){
		std::cout << "A constructor\n";
	}
	~A(){
		std::cout << "A destructor\n";
	}
	void set(std::shared_ptr<C> ptr){
		this->ptr = ptr;
	}
};

class B{
private:
	std::weak_ptr<C> ptr;
public:
	B(){
		std::cout << "B constructor\n";
	}
	~B(){
		std::cout << "B destructor\n";
	}
	void set(std::shared_ptr<C> ptr){
		this->ptr = ptr;
	}
};

class C{
private:
	std::shared_ptr<A> ptr1;
	std::shared_ptr<B> ptr2;
public:
	C(std::shared_ptr<A> p1, std::shared_ptr<B> p2){
		std::cout << "C constructor\n";
		this->ptr1 = p1;
		this->ptr2 = p2;
	}
	~C(){
		std::cout << "C Destructor\n";
	}
};

int main()
{
	std::shared_ptr<A> a(new A());
	std::shared_ptr<B> b(new B());
	std::shared_ptr<C> c(new C(a,b));
	a->set(std::shared_ptr<C>(c));	
	b->set(std::shared_ptr<C>(c));	
	return 0;
}
