#include<iostream>
#include<string.h>

class Str
{
public:
	std::string str1;
	Str(){
		str1 = "";
	}
	Str(std::string val){
		str1 = val;
	}
	
	Str operator+(Str const &ref){
		Str result;
		result.str1 = str1 + ref.str1;
		return result;
	}
	bool operator>(Str const &ref){
		int v1 = str1.length();
		int v2 = (ref.str1).length();
		if(v1 > v2){
			std::cout << str1 << " parameter is having higher length\n";
			return true;
		}else if(v2 > v1){
			std::cout << ref.str1 << " parameter is having higher length\n";
			return false; 
		}else{
			std::cout << "Both are equal\n";
			return true;
		}
	}
	void  operator=(Str const &ref){
		str1 = ref.str1;
	}
	/*
	std::string operator+(Str const &ref){
		std::string result;
		result = str1 + ref.str1;
		return result;
	}	
	*/
};

int main()
{
	Str o1("Hello Hello");
	Str o2("World!");
	std::cout << "o1.str1 " << o1.str1 << std::endl;
	std::cout << "o2.str1 " << o2.str1 << std::endl;
	std::cout << "Overloading the assignment operator\n";
	o1 = o2;
	std::cout << "o1.str1 " << o1.str1 << std::endl;
	std::cout << "o2.str1 " << o2.str1 << std::endl;
	return 0;
}
