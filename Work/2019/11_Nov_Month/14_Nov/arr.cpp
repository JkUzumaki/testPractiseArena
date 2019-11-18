#include<iostream>
#include<array>

int main()
{
	std::array<int, 5> a = {1, 2, 3, 4, 5};
	std::cout << "Size of array is " << a.size() << "\n";
	auto pos = a.begin();
	std::cout << std::endl;
	while(pos != a.end()){
		std::cout << *pos << "\t"; 
		pos++;
	}
	std::cout << "\narray a data at index 1 : " << a.at(1) << "\n";
	std::cout << "\narray a data at index 4 : " << a[4] << "\n";
	std::cout << "\nFront: " <<a.front();
	std::cout << "\nend: " << a.end();
	std::cout << "\nLast: " << a.back();
	std::cout << "\n";
	pos = a.begin();
	while(pos != a.end()){
		std::cout << *pos << "\t"; 
		pos++;
	}
	std::cout << "\n";
	return 0;
}
