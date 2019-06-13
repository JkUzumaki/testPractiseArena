#include <iostream>
using namespace std;

class Square;  // forward declaration

class Rectangle {
	int width, height;

public:
	Rectangle(int w = 1, int h = 1):width(w),height(h){
		cout << "The width " << w << " height " << h << endl;
	} 
	friend void display(Rectangle &, Square &);// friend function prototype
};

class Square {
	int side;

public:
	Square(int s = 1):side(s){
		cout << "The side of square " << s << endl;
	} 
	friend void display(Rectangle &, Square &);// friend function prototype
};

void display(Rectangle &r, Square &s) { // friend function definition
	cout << "Rectangle: widht * height = " << r.width * r.height << endl;
	cout << "Square: side * side = " << s.side * s.side << endl;
	cout << "Adding the the rect width and square side: " << r.width + s.side;
	cout << "\nMult the rect height and sq side: " << r.height * s.side << endl;
}

int main () {
	Rectangle rec(5,10);
	Square sq(5);
	display(rec,sq);// Calling friend function
	return 0;
}
