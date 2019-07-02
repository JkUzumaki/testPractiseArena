// Program to print the max number of letters present in a string
#include<iostream>
#include<string.h>

int main()
{
	int length =0;
	std::string str;
	std::cout << "Enter the string:\n";
	//std::cin.ignore();
	std::getline(std::cin, str);
	//std::cout << "Data : " << str  << " size " << str.size() << std::endl;
	length = str.size();
	std::string maxStr, newStr;
	int i = 0;
	int wcount = 0;
	int max = 0;
	while(i <= length){
		if(str[i] != ' '){
			newStr += str[i];
			wcount++;
			if(wcount > max){
				maxStr = newStr;
				max = wcount;
			}
		}else{
			newStr = "";
			wcount = 0;
		}
		i++;
	}
	std::cout << "The maximum number of letter in a string " << max << " the STR: " << maxStr << std::endl;
}
