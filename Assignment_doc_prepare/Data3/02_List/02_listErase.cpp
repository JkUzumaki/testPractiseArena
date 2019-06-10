#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

int main()
{
	std::list<int> listInt({2,3,4,6,4,9,1,2,8,9,4,6,2,4,9});
	// 
	std::copy(listInt.begin(), listInt.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::list<int>::iterator it = ++(listInt.begin());
	// Erasing element in list based on iterator
	it = listInt.erase(it);

	// Displaying the list
	std::copy(listInt.begin(), listInt.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	
	it++;
	// Erasing element from the iterator position to the end of the list
	listInt.erase(it, listInt.end());

	// Displaying the list
	std::copy(listInt.begin(), listInt.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	return 0;
}
