#include <iostream>
using namespace std;

class Rectangle {
	int width, height;

public:
	Rectangle(int w = 1, int h = 1):width(w),height(h){} 
	friend void display(Rectangle &);
};

void display(Rectangle &r) {
	cout << "The friend function accessing provate data:\n"<< r.width * r.height << endl;
}

int main () {
	Rectangle rect(5,10);
	display(rect);
	return 0;
}

