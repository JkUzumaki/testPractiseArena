#include<iostream>

int main()
{
	const int size = 5;
	int arr[size] = {50, 40, 10, 30, 20};
	int i, j;
	int flag = 0;
	int temp = 0;
	for(i = 0; i < size; i++){
		for(j = i+1; j > 0; j--){
			if(arr[j] < arr[j-1]){
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	std::cout << "The data entered:\n";
	temp = 0;
	while(temp != size){
		std::cout << arr[temp] << " ";
		temp++;
	}
	std::cout << std::endl;
	return 0;
}
