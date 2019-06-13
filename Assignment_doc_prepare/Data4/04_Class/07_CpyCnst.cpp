#include<iostream>
#include<cstring>
using namespace std;

class String1
{
private:
        char *s;
        int size;
public:
        String1(const char *str = NULL); // constructor 
        ~String1() { delete [] s; }// destructor 
        void print() { cout << s << endl; } // Function to print string 
        void change(const char *); // Function to change 
	String1(String1 ); //Copy constructor
};

String1::String1(const char *str)
{
        size = strlen(str);
        s = new char[size+1];
        strcpy(s, str);
}

void String1::change(const char *str)
{
        delete [] s;
        size = strlen(str);
        s = new char[size+1];
        strcpy(s, str);
}

String1::String1( String1 old_str) 
{ 
    size = old_str.size; 
    s = new char[size+1]; 
    strcpy(s, old_str.s); 
} 


int main()
{
        String1 str1("Hello World!");
        String1 str2 = str1;

        str1.print(); // what is printed ? 
        str2.print();

        str2.change("Hello Universe!");

        str1.print(); // what is printed now ? 
        str2.print();
        return 0;
}
