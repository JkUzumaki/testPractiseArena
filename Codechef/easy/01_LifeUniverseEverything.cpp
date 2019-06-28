#include<iostream>

int main()
{
	int size = 0;
	std::cin >> size;
	
	int arr[size];
	for(int i =0; i < size; i++)
		std::cin >> arr[i];

	for(int i = 0; i < size; i++){
		if(arr[i] != 42)
			std::cout << arr[i] << std::endl;
		else
			break;
	}	
	return 0;
}
