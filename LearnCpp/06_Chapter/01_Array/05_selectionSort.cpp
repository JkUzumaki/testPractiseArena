#include<iostream>

void swapp(int* arr1, int* arr2)
{
	int temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

int main()
{
	std::cout << "Selection sort\n";
	int size = 0;
	int j = 0;
	int temp = 0;
	int pos = 0;
	std::cout << "Enter the size of the array\n";
	std::cin >> size;
	//Dynamic allocation
	int *arr = new int[size];

	//Assign value to array	
	std::cout << "Enter the data to be sorted\n";
	for(int i = 0;i < size; i++){
		std::cin >> arr[i];
	}

	//Print the array
	std::cout << "Array to be SORTED\n";
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	//Sort
        for(int i = 0; i < size; i++){
		pos = i;		
		for(j = i+1; j < size; j++){
			if(arr[pos] > arr[j]){
				pos = j;
			}
		}
	//	if(pos != i)
			swapp(&arr[i], &arr[pos]);
		
	}
	
	//Print the array
	std::cout << "Array SORTED\n";
	for(int i = 0; i < size; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	
	//Deallocation
	delete[] arr;
	return 0;
}
