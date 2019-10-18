#include<iostream>

class test{
public:
	int *num;
	int n;
	test(){
		num = &n;
	}
	test(const test &ref){
		num = new int;
		*num = ref.n;
	}
	void set(int m){
		*num = m;
	}
	void get(){
		std::cout << "num : " << *num << std::endl;
	}
};

int main()
{
	test a;
	a.set(10);
	a.get();
	test b = a;
	b.get();
	a.set(99);
	std::cout << "After modify\n";
	a.get();
	b.get();
}
