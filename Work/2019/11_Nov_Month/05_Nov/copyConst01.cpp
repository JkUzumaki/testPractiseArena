#include<iostream>

class test{
public:
	int a, b;
	int *ptr;
	/*test(test const &ref){
		a = ref.a;
		b = ref.b;
		ptr = new int;
		ptr = &a;
	}*/
	test(int v1, int v2){
		a = v1; b= v2;
		ptr = new int;
		ptr = &a;
	}
	test(){}
	~test(){
		/*
		if(ptr != NULL)
			delete ptr;
		*/
	}
};
int main()
{
	test t1(10, 20);
	std::cout << "t1.a " << t1.a << " t1.b" << t1.b << std::endl;
	std::cout << "t1.*ptr " << *(t1.ptr) << std::endl;
	test t2 = t1;
	*(t1.ptr) = 99;
	std::cout << "t1.*ptr " << *(t1.ptr) << std::endl;
	std::cout << "t2.*ptr " << *(t2.ptr) << std::endl;
	std::cout << "t2.a " << t2.a << " t2.b" << t2.b << std::endl;
	return 0;
}
