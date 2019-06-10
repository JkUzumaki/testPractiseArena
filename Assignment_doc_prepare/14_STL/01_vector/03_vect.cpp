#include <iostream>
#include <vector>

int main()
{
	int arr[] = {1,2,3,4,5};
	std::vector<int> v(arr, arr+sizeof(arr)/sizeof(int));

	for(int x:v)
		std::cout << x << " ";
	std::cout << "\n";
	return 0;
}

