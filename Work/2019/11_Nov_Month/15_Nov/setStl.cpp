#include<iostream>
#include<set>
#include<vector>
#include<iterator>
#include<algorithm>

int main()
{
	std::set<int> s1 = {5,4,2,3,100,1};
	std::set<int> s2 = {5, 3, 4, 10, 20};
	
	std::vector<int> v(s1.size(), s2.size());
	std::cout << "\nFirst set values are ..." << std::endl;
	copy(s1.begin(), s1.end(), std::ostream_iterator<int>(std::cout, "\t"));
	std::cout << std::endl;

	std::cout << "\nSecond set values are ..." << std::endl;
	copy(s2.begin(), s2.end(), std::ostream_iterator<int>(std::cout, "\t"));
	std::cout << std::endl;
	
	auto pos = set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
//	auto pos = set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin());
	v.resize(pos - v.begin());
	
	std::cout << "\nValues present in set one but not in set two are ..." << std::endl;
	copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\t"));
	std::cout << std::endl;

	return 0;
}
