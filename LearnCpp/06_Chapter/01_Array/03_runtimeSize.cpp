#include<iostream>

int main()
{
	int len;
	std::cin >> len;
	int arr[len];
	arr[len-1] = 101;
	std::cout << arr[len-1];
}
