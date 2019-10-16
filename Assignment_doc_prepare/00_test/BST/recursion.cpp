#include<iostream>

int factorial(int num){
	if(num < 0){
		std::cout << "Number cannot be lesser than zero\n";
		return -1;
	}else if(num == 1){
		return 1;
	}else{
		return (num * factorial(num-1));
	}
}

int main(){
	int fact = 0;
	int data = 0;
	std::cout << "Enter the number\n";
	std::cin >> data;
	fact = factorial(data);
	std::cout << "The factorial of the number " << data << " is " << fact << std::endl;
	return 0;
}
