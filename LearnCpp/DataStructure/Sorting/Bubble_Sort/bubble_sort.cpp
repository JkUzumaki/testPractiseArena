#include<iostream>

int main()
{
	int data;
	std::cout << "Enter the size of the array to be sorted\n";
	std::cin >> data;
	const int size = data;
	int arr[size];
	std::cout << "\nEnter data to array\n";
	int temp = 0;
	while(temp != size){
		std::cin >> arr[temp];
		temp++;
	}
	temp = 0;
	for(int i = 0; i < size; i++){
		for(int j = size-1, k = size-2; j >= i; j--,k--){
			if(arr[j] < arr[k]){
				temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}
		}
	}
	std::cout << "\nThe bubble sorted array:\n";
	temp = 0;
	while(temp != size){
		std::cout << arr[temp] << " ";
		temp++;
	}
	std::cout << std::endl;
	return 0;
}
