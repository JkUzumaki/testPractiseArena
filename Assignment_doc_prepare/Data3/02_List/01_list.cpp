#include<list>
#include<iostream>

int main()
{
	std::list<int> l;
	
	l.push_back(30);
	l.push_back(40);
	l.push_front(20);
	l.push_front(21);
	
	std::list<int>::iterator it = l.begin();

	while(it != l.end()){
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";
}
