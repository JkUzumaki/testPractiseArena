#include<iostream>
#include<iterator>

int main()
{
	int arr[] = {4,5,6,7,8,9};
	for(int i = 0; i < std::size(arr); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
