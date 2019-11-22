#include<iostream>

class Box
{
private:
	int length;
	int breadth;
	int height;
	int volume;
public:
	//Constructor
	Box(int v1, int v2, int v3):length(v1), breadth(v2), height(v3){
		volume = length * breadth * height;
	}
	Box() = delete;

	//Get volume
	void  getVolume(){
		std::cout << "The volume is " << this->volume << std::endl;
	}

	//Overload > operator
	bool operator>(Box& ref){
		if(ref.volume > this->volume)
			return false;
		else
			return true;
	}

	//Overload + operator
	Box operator+(Box &ref){
		Box temp(0, 0, 0);
		temp.length = ref.length + this->length;
		temp.breadth = ref.breadth + this->breadth;
		temp.height = ref.height + this->height;
		temp.volume = ref.volume + this->volume;
		return temp;
	}
};

int main()
{
	Box b1(10, 20, 30);
	b1.getVolume();
	Box b2(1,2,3);
	if(b2 > b1)
		std::cout << "Box2 is bigger\n";
	else
		std::cout << "Box1 is bigger\n";
	Box b3(0,0,0);
	b3 = b1 + b2;	
	std::cout << "Box 3 :";
	b3.getVolume();
}
