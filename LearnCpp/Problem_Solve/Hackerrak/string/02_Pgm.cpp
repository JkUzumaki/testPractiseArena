#include<iostream>
#include<sstream>

int main()
{
	std::stringstream ss("23,4,56");
	std::string str1 = ss.str();
	int index = 0;
	int count = 0;
	//Finding the number of commas
	while(str1[index] != '\0'){
		if(str1[index] == ',')
			count++;
		index++;
	}
	
	int size = count + 1;
	std::string arr[size];
	index = 0;
	count = 0;
	//Inserting the elements to array
	while(str1[index] != '\0'){
		if(str1[index] == ',')
			count++;
		else
			arr[count] += str1[index];
		index++;
	}

	count = 0;
	//Printing the array
	while(count < size){
		std::cout << arr[count] << std::endl;
		count++;
	}
	return 0;
}
