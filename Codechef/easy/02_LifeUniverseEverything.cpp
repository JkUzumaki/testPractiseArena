#include<iostream>

int main()
{
	int val= 0;
	while(1){
		std::cin >> val;
		if(val != 42)
			std::cout << val << std::endl;
		else
			break;
	}	
	return 0;
}
