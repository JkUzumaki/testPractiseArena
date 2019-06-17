#include<iostream>
//using namespace std;

int main()
{
	struct a{
		int num;
	};
	a obj[2];
	obj[0].num = 10;
	obj[1].num = 20;

	for(int i = 0; i < 2; i++){
		std::cout << "The structure array contains " << obj[i].num << std::endl; 
	}
	
}
