#include<iostream>
//using namespace std;
class doo
{
public:
	int a;
	void setB(int val){
		b = val;
	}
	int getB(){
		return b;
	}
private:
	int b;
};

int main()
{
	doo d;	
	d.setB(10);
	int valB = d.getB();
	std::cout << valB << std::endl;
}

	/*struct foo
	{	
		int a;
		void setB(int val){
			b = val;
		}
		int getB(){
			return b;
		}
	private:
		int b;
	}t;*/
