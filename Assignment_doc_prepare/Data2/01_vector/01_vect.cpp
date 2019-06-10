#include<iostream>
#include<vector>

int main()
{
	std::vector<int> vectInt;
	
	for(int i = 0; i < 10; i++)
		vectInt.push_back(i);

	std::vector<int>::iterator it = vectInt.begin();
	while(it != vectInt.end()){
		std::cout << *it << ", ";
		it++;
	}
	
	std::cout << std::endl;
	
	for(int i = 0; i < vectInt.size(); i++)
		std::cout << vectInt[i] << ", ";
	std::cout << "\n";
	return 0;
}
