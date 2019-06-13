#include<list>
#include<algorithm>
#include<iostream>
#include<iterator>

int main()
{
	std::list<int> listInt({2, 3, 3, 4, 8, 9, 4, 6, 8, 3});
	
	std::list<int>::iterator it = listInt.begin();
	while(it != listInt.end()){
		if((*it) % 3 == 0){
			it = listInt.erase(it);
		}else{
			it++;
		}
	}

	std::for_each(listInt.begin(), listInt.end(), [](const int& val){
		std::cout << val << ", ";
	});
	std::cout << std::endl;
	return 0;
}
