#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int checkPrime(int big){
	if(big == 2){
		return 1;
	}
	int test = big - 1;
	while(test != 1){
		if(big % test == 0)
			return 0;
		test--;
	}
	return 1;
}

int main()
{
	int tEntry = 0;
	int dSpace = 0;
	int big = 0;
	int cmp = 0;
	int prime = 0;

	std::vector<int> vPrime;
	std::cin >> tEntry;
	dSpace = 2 * tEntry;

	int *aPtr = new int [dSpace];
	//Input the data for the array
	int data = 0;
	int test = 0;
	while(test != dSpace){
		 //Get the value
		 std::cin >> data;
		 *(aPtr+test) = data;
		 //Comparing the value to get the higher value
		 cmp = data;
		 if(cmp > big)
		 	big = cmp;
		 test++;
	}

	//Getting the prime number
	test = big;
	while(test != 1){
		 prime = checkPrime(test);
		 if(prime == 1){
		  vPrime.push_back(test);
		 }
		 test--;
	}
	sort(vPrime.begin(), vPrime.end());
/*
	std::cout << "Prime number in the given list\n";
	for(std::vector<int>::iterator it = vPrime.begin(); it != vPrime.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << "\nThe size of the vector: " << vPrime.size();
*/
	int start, end; 
	test = 0;
	while(tEntry--){
		start = *(aPtr+test);
		test++;
		end = *(aPtr+test);
		test++;
		for(std::vector<int>::iterator it = vPrime.begin(); it != vPrime.end(); it++){
			if(*it >= start && *it <= end)
				std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	delete [] aPtr;
	return 0;
}

