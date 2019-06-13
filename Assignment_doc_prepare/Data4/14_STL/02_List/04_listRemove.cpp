#include<iostream>
#include<list>

int main()
{
	std::list<int> listInt({2, 3, 4, 6, 9, 1, 2, 8, 9, 4, 6, 2});

	listInt.remove(4);
	
	for(int val:listInt)
		std::cout << val << " ";
	std::cout << "\n";
	return 0;
}
