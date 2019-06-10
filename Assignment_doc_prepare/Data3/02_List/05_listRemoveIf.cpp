#include<iostream>
#include<list>
#include<algorithm>

int main(){
	std::list<int> listInt({2,3,4,6,4,9,1,2,8,9,4,6,2});

	listInt.remove_if([](const int& val){
		if(val >= 2 && val < 5)
			return true;
		else
			return false;
	});
	
	for(int val: listInt)
		std::cout << val << " ,";
	std::cout << std::endl;
	return 0;
}
