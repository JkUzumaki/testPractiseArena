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

class SPtr
{
private:
        static int reference;
        A* ptr;
public:
        SPtr(){
                reference++;
                std::cout << "Const reference = " << reference << std::endl;
                ptr = new A();
        }
        ~SPtr(){
                reference--;
                std::cout << "Dest reference = " << reference << std::endl;
                if(reference == 0){
                        delete ptr;
                    std::cout << "No more reference " << reference << std::endl;
                }
        }
        SPtr(const SPtr &obj){
                reference++;
                ptr = obj.ptr;
                std::cout << "CpyConst reference = " << reference << std::endl;
        }
        SPtr& operator=(SPtr& obj){
                //reference++;
                this->ptr = obj.ptr;
                std::cout << "Assign operator reference = " << reference << std::endl;
                return *this;
        }
        A* operator->() const {
                return ptr;
        }

};

int SPtr::reference=0;

int main()
{
/*         SPtr *obj=new SPtr();
         (*obj)->show();
         delete obj;
*/
    SPtr obj;
    {
        SPtr obj1 = obj;
        SPtr obj2;
        {
            
            obj2 = obj1;
        }
    }
    obj->show();
}



