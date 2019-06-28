#include<iostream>
class Animal
{
public:
        Animal()
        {
	//std::cout << "Animal const\n";
}
        ~Animal()
        {
//	std::cout << "Animal dest\n";
}
        virtual void eat()
        {std::cout << "Animal eat generic food\n";}
};

class Cat: public Animal
{
public:
        Cat()
        {//std::cout << "Cat Const\n";}
}
        ~Cat()
        {//std::cout << "Cat dest\n";}
}
        void eat()
        {std::cout << "Cat eat rat\n";}
};

void func(Animal *x)
{x->eat();}

int main()
{
	Cat obj;
        Animal *a = obj;
  	a->eat();
      /*Cat *c = new Cat();
        a->eat();
        c->eat();
        func(a);
        func(c);
        delete a;
        delete c;
*/
}
