#include<iostream>

class check
{
    private:
        int data;
    public:
        // constructor
        check(int i = 0): data(i){}
        //Prefix
        check operator++(){
            check temp;
            temp.data = ++data;
            return temp;
       }
        //Postfix
        check operator++(int){
            check temp;
            temp.data = ++data;
            return temp;
        }

        void display()
        {
            std::cout << "The data : " << data << std::endl;
        }
};

int main()
{
    check obj;
    obj.display();
    std::cout << "prefix increment\n";
    ++obj;
    obj.display();
    std::cout << "postfix increment\n";
    obj++;
    obj.display();
}
