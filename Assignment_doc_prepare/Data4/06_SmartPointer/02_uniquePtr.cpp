#include<iostream>

class A
{
public:
       A()
{}
        void show()
        {
                std::cout << "Hello\n";
        }
};

class Uptr
{
private:
        A* ptr;
public:
        Uptr(){
                ptr = new A();
        }
        ~Uptr(){
                        delete ptr;
                }
        }
        Uptr(const Uptr &obj){
                ptr=new A();
                ptr = obj.ptr;
                delete obj.ptr;
                obj.ptr=nullptr;
        }
        Uptr& operator=(Uptr& obj){
                this->ptr = obj.ptr;
                delete obj.ptr;
		obj.ptr = nullptr;
		return *this;
        }
        A* operator->() const {
                return ptr;
        }

};


int main()
{
    Uptr obj;
}
