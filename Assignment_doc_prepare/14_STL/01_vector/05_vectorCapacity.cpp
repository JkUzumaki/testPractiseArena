#include<iostream>
#include<vector>

struct sample
{
	sample(){}
	sample(const sample& obj){
		std::cout << "Sample copy constructor\n";
	}
};

int main()
{
	std::vector<sample> v;
	std::cout << "Capacity :: " << v.capacity() << "\n";
	std::cout << "size :: " << v.size() << "\n";
	int capacity = v.capacity();
	
	for(int i = 0; i < capacity + 1; i++)
		v.push_back(sample());

	std::cout << "capacity :: " << v.capacity() << "\n";
	std::cout << "size :: " << v.size() << "\n";

	for(int i = 0; i < capacity + 1; i++)
		v.push_back(sample());

	std::cout << "Capacity :: " << v.capacity() << "\n";
	std::cout << "size :: " << v.size() << "\n";
	
	std::cout << "\n";

	return 0;
}
