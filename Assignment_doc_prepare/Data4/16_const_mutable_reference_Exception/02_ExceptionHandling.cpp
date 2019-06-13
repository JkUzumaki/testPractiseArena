#include<iostream>
//#include<conio.h>
using namespace std;

int main()
{
	int a = 10, b = 0, c;
	try{
		if(b == 0){
			throw "divison by zero is not possible";
			c = a/b;
		}
		
	}
	catch (char* ex){
		cout << ex;// << endl;
	}
	return 0;
}
