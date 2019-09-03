// c++ program for nested list 

#include <iostream> 
#include <iterator> 
#include <list> 
using namespace std; 
/* 
void printNestedList(list<list<int> > nested_list) 
{ 
	cout << "[\n"; 

	// nested_list`s iterator(same type as nested_list) 
	// to iterate the nested_list 
	list<list<int> >::iterator nested_list_itr; 

	// Print the nested_list 
	for (nested_list_itr = nested_list.begin(); 
		nested_list_itr != nested_list.end(); 
		++nested_list_itr) { 

		cout << " ["; 

		// normal_list`s iterator(same type as temp_list) 
		// to iterate the normal_list 
		list<int>::iterator single_list_itr; 

		// pointer of each list one by one in nested list 
		// as loop goes on 
		list<int>& single_list_pointer = *nested_list_itr; 

		for (single_list_itr = single_list_pointer.begin(); 
			single_list_itr != single_list_pointer.end(); 
			single_list_itr++) { 
			cout << " " << *single_list_itr << " "; 
		} 
		cout << "]\n"; 
	} 
	cout << "]"; 
}  
*/

void printNestedList(list<list<int> > nested_list) 
{
	
	for(auto it = nested_list.begin(); it != nested_list.end(); it++){
		for(auto it1 = )
	}
}

// Driver code 
int main() 
{ 
	// instead integer type can have any data type 
	list<list<int> > nested_list; 
	list<int> single_list; 
	list<int> single_list2; 
	list<int> single_list3; 
	int n, m, num; 
/*
	// number of lists in nested list 
	n = 3; 

	for (int i = 0; i < n; i++) { 

		// number of elements in list 
		m = i + 2; 
		for (int j = 0; j < m; j++) { 
			num = i + j; 
			single_list.push_back(num); 
		} 

		nested_list.push_back(single_list); 

		// delete all elements from single_list 
		single_list.erase(single_list.begin(), 
						single_list.end()); 
	} 
*/
	single_list.push_back(10);
	single_list.push_back(20);
	
	single_list2.push_back(50);
	single_list2.push_back(60);
	
	single_list3.push_back(70);
	single_list3.push_back(80);
	
	nested_list.push_back(single_list);
	nested_list.push_back(single_list2);
	nested_list.push_back(single_list3);
	
	printNestedList(nested_list); 

	return 0; 
} 
/*
	{
	{L1}, {L2}
	}
*/

///////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<map>

int main()
{
    //std::multimap <int, int> m;
     std::map <int, int> m;
    m[1] = 100;
    std::cout << "m[1] " << m[1] << std::endl;
    m[1] = 200;
    std::cout << "m[1] " << m[1] << std::endl;
}

///////////////////////////////////////////////////////////////////////////////////////

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <typeinfo>
class base
{
  public:
  base(){
      std::cout << "base const\n";
  }
  ~base(){
      std::cout << "base destructor\n";
  }
  virtual void fn(){
      std::cout << "Base::fn\n";
  }
};

class der:public base
{
  public:
  der(){
      std::cout << "der const\n";
  }
  ~der(){
      std::cout << "der destructor\n";
  }
  void fn(){
      std::cout << "der::fn\n";
  }
};

int main()
{
    der obj;
    std::cout << "type of int: " << typeid(5).name() << std::endl;
    std::cout << "type of string: " << typeid("HelloWorld").name() << std::endl;
    std::cout << "type of char: " << typeid('c').name() << std::endl;
    std::cout << "type of double: " << typeid(5.8765).name() << std::endl;
std::cout << "type of der: " << typeid(obj).name() << std::endl;
    
}

//////////////////////////////////////////////////////////////

#include<iostream>

class square
{
	int a;
public:
	square(int side):side(a){}
	
	int operator+(square q){
		int total = q.a + this->a;
		std::cout << "sum of two square sides : " << total << std::endl;
	}
};

int main()
{
	square ob1(10);
	square ob2(20);
	square ob3 = ob1 + ob2;
	return 0;
}
//
CHECK THIS ONE BELOW
#include<iostream>

class square
{
	int a;
public:
	//square(int side):a(side){}
	square (int side){
	    a = side;
	}
	int operator+(square q, square q1){
		int total = q1.a + q.a + this->a;
		std::cout << "sum of two square sides : " << total << std::endl;
	}
};

int main()
{
	square ob1(10);
	square ob2(20);
	square ob3(20);
	square ob4 = ob1 + ob2 + ob3;
	return 0;
}

////////////////////////////////////////////////////////////////////////

// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

void print_block (int n, char c) {
  // critical section (exclusive access to std::cout signaled by locking mtx):
  std::lock_guard<std::mutex> lock(mtx);
  //mtx.lock();
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
  //mtx.unlock();
}

int main ()
{
  std::thread th1 (print_block,50,'*');
  std::thread th2 (print_block,50,'$');

  th1.join();
  th2.join();

  return 0;
}

////////////////////////////////////////////////////////////////////////////

#include<iostream>

class square
{
	int a;
public:
	square(int side):side(a){}
	
	int operator=(square q){
		this->a = q.a;
	}
	void get()
	{
		std::cout << "a is " << a << std::endl;
	}
};

int main()
{
	square ob1(10);
	//square ob2(20);
	square ob3;
	ob3	= ob1 ;//+ ob2;
	ob3.get();
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

#include<iostream>

class square
{
	int a;
	int *q;
public:
    square(){
        a = 0;
        q = NULL;
    }
	square(int side, int &d){
	    a = side;
	    q = &d;
	}
	/*
	int operator=(square n){
		this->a = n.a;
		*q = n.q;
	}*/
	void get()
	{
		std::cout << "a is " << this->a << " *q is " << *q << std::endl;
	}
};

int main()
{   
    {
        int val = 20;
	    square ob1(10, val);
        ob1.get();
        square ob2;
        std::cout << "Before assigning\n";
        ob2.get();
        ob2 = ob1;
        std::cout << "After assigning\n";
        ob2.get();
    }
	/*square ob3;
	ob3.get();
	ob3	= ob1 ;
	ob3.get();
	*/
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// SHALLOW COPY
#include<iostream>

class test
{
private:
	int a;
	int *b;
public:
	test()
	{
		b = new int;
	}
	void set(int v1, int v2){
		a = v1;
		*b = v2;
	}
	void get()
	{
		std::cout << "a : " << a << " b: " << *b << std::endl;
	}
};

int main()
{
	test t1;
	std::cout << "t1 val: ";
	t1.set(10, 20);
	t1.get();
	std::cout << "t2 is assigned t1 with default copy constructor\n";
	test t2 = t1;
	
	t1.set(30, 40);
	std::cout << "t1 val: ";
	t1.get();
	std::cout << "t2 val: ";
	t2.get();
	
	return 0;
}

//////////////////////////////////////////////////////////////////////
// DEEP COPY

#include<iostream>

class test
{
private:
	int a;
	int *b;
public:
	// Constructor
	test()
	{
		b = new int;
	}
    // Destructor
	~test()
	{
	    delete b;
	}
	// Copy constructor
	test(const test &t){
		b = new int;
		a = t.a;
		*b = *(t.b);
	}
	// = operator
	test operator=(const test &t){
	    a = t.a;
		*b = *(t.b);
		return *this;
	}
	// SET
	void set(int v1, int v2){
		a = v1;
		*b = v2;
	}
	// GET
	void get()
	{
		std::cout << "a : " << a << " b: " << *b << std::endl;
	}
};

int main()
{   
    test t2;
    {
    	test t1;
    	std::cout << "t1 val: ";
    	t1.set(10, 20);
    	t1.get();
    	std::cout << "t2 is assigned t1 with default copy constructor\n";
    	t2 = t1;
    	t1.set(30, 40);
    	std::cout << "t1 val: ";
    	t1.get();

    }
    //std::cout << "t1 val: ";
	//t1.get();
	std::cout << "t2 val: ";
	t2.get();

	return 0;
}