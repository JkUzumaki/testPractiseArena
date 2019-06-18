#include <iostream>
#include <cstddef> // for NULL
 
void print(int x)
{
	std::cout << "H\n";
	std::cout << "Aprint(int): " << x << '\n';
}
 
void print(int *x)
{
	if (!x)
		std::cout << "Zprint(int*): null\n";
	else
		std::cout << "Cprint(int*): " << *x << '\n';
}
 
int main()
{
	int *x { nullptr };
	print(x); // calls print(int*)
 
	print(nullptr); // calls print(int*) as desired
 
	return 0;
}
