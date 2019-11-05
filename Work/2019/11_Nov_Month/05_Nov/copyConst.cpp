#include<iostream>

class test{
public:
	int a, b;
/*	test(test const &ref){
		a = ref.a;
		b = ref.b;
	}
*/	test(int v1, int v2){
		a = v1; b= v2;
	}
	test(){}
};
int main()
{
	test t1(10, 20);
	std::cout << "t1.a " << t1.a << " t1.b" << t1.b << std::endl;
	test t2 = t1;
	std::cout << "t2.a " << t2.a << " t2.b" << t2.b << std::endl;
	return 0;
}
