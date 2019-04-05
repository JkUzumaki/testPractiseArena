#include<iostream>

int main()
{

	//Declaring and initializing variables
	int arr[] = {30, 10, 40, 50, 5, 20};
	int arr_count = sizeof(arr) / sizeof(arr[0]);
	int key =0, i =0, j = 0;	
	std::cout << "count " << arr_count << std::endl;	

	//Printing array before sort	
	std::cout << "The array before insertion sort\n";
	for(int count = 0; count < arr_count ; count++){
		std::cout << arr[count] << " ";
	}	
	std::cout << "\n";
	
	//Sorting happens here
	for(j = 1; j < arr_count ; j++){
		key = arr[j];
		i = j - 1;
		while(i >= 0 && arr[i] > key){
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
	
	//Printing array after sort
	std::cout << "The array after insertion sort\n";
	for(int count = 0; count < arr_count ; count++){
		std::cout << arr[count] << " ";
	}	
	std::cout << "\n";
	
	return 0;	
}
