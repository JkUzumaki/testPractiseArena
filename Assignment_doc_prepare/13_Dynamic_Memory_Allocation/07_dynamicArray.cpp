#include<iostream>

int main()
{
	std::cout << "Enter a positive integer: ";
	int length;
	std::cin >> length;
	
	int* array = new int[length];
	std::cout << "I just allocated an array of integers of length " << length << "\n";
	array[0] = 5;
	for(int i = 0; i < length; i++)
		std::cout << array[i] << " ";
	std::cout << "\n";
	delete[] array;
	for(int i = 0; i < length; i++)
		std::cout << array[i] << " ";
	std::cout << "\n";
	return 0;
}

