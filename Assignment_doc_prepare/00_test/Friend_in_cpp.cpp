//Friend 

//Friend function
The private member or data of a class can be accessed only by the member of the class.
But there is another way to access them,
A friend function,
	Eventhough its not a member of the class but it can access the private member of the class. 

//Pgm_01
#include <iostream>

class Rectangle {
	int width, height;
public:
	Rectangle(int w = 1, int h = 1):width(w),height(h){} 
	friend void display(Rectangle &);	// Friend function in public or in private will work the same way
};

void display(Rectangle &r) {//Here display is a friend function to the class Rectangle and we didnt use return_type className::function(param){...}
	std::cout << "Width : "<<r.width << " Height: "<< r.height << std::endl;
}

int main () {
	Rectangle rect(5,10);
	display(rect);
	Rectangle r;
	display(r);
	return 0;
}
//----------------------------------------------------------------------------

But we could have used the display as a member function and have accessed the private data of the class. But why do we need a friend function.
1. A friend function can be friendly to 2 or more class.
2. Friend function does not belong to any class. Hence it can access the private data of both the class.
3. Friend function can be used to perform operation between two class.

Note:
	Use of friend function is an out of object oriented programming methodology.
	1. Friend functions are not members of any class but they can access private data of the class to which they are a friend.
	2. Because they are not members of any class, you should not call them using the dot operator.
	
//Friend class
Just like function are being made friend of a class, classes can also be made friend of another class.
The friend class also have access to all the private members of the other class.

//Pgm_02
/*
	Here the Square is a friend to rectangle.
	So square can access the private members of the rectangle.
	But rectangle cannot access the private members of the square.
	In order for rectangle to access the private data of square a friend function needs to be created in the rectangle.
*/
#include <iostream>
class Square;

class Rectangle {
	int width, height;
public:
	Rectangle(int w = 1, int h = 1):width(w),height(h){} 
	void display() {std::cout << "Rectangle: " << width * height << std::endl;};
	void morph(Square &);
	//friend class Square;
};

class Square {
	int side;
public:
	Square(int s = 1):side(s){} 
	void display() {std::cout << "Square: " << side * side << std::endl;};
	friend class Rectangle;
};

void Rectangle::morph(Square &s) {
	width = s.side;
	height = s.side;
}

int main () {
	Rectangle rec(5,10);
	Square sq(5);
	std::cout << "Before:" << std::endl;
	rec.display();
	sq.display();

	rec.morph(sq);
	std::cout << "\nAfter:" << std::endl;
	rec.display();
	sq.display();
	return 0;
}
//----------------------------------------------------------------------------
//Pgm_03
/*
	When both the class are friend fuinctions to each other then they can access all the private data
*/
#include <iostream>
class Square;

class Rectangle {
	int width, height;
public:
	Rectangle(int w = 1, int h = 1):width(w),height(h){} 
	void display() {std::cout << "Rectangle: " << width * height << std::endl;};
	void morph(Square &);
	friend class Square;
};

class Square {
	int side;
public:
	Square(int s = 1):side(s){} 
	void display() {std::cout << "Square: " << side * side << std::endl;};
	friend class Rectangle;
	void morph(Rectangle &r);
};

void Rectangle::morph(Square &s) {
	width = s.side;
	height = s.side;
}

void Square::morph(Rectangle  &s) {
	side = s.height;
}

int main () {
	Rectangle rec(5,10);
	Square sq(5);
	std::cout << "Before:" << std::endl;
	rec.display();
	sq.display();

	//rec.morph(sq);
	sq.morph(rec);
	std::cout << "\nAfter:" << std::endl;
	rec.display();
	sq.display();
	return 0;
}
//----------------------------------------------------------------------------
