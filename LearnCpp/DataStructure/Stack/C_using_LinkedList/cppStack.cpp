#include<iostream>
#include "student.h"

int size = 0;
int asize = 0;

class stack;

template <class T>
class iterate
{
    stack sObj;
public:
    iterate(stack stk):sObj(stk)
    {}
    // overload prefix
	// To iterate through the stack
    bool operator++()
    {
        if(sObj.Head == NULL)
            return false;
        else{
            sObj.Head = sObj.Head->next;
            return true;
        }
    }
    // overload postfix
	// To iterate through the stack
    bool operator++(int)
    {
        if(sObj.Head == NULL)
            return false;
        else{
            sObj.Head = sObj.Head->next;
            return true;
        }
    }
    //To check whether whether node is null
	bool check()
	{
		if(stk.Head == NULL)
			return false;
		else
			return true;
	}
	//To return the value
	T getData()
	{
		return stk.Head->data;
	}
};


template <class T>
class stack
{
private:
    struct node
    {
        T data;
        struct node *next;
    }*Head;
public:
    stack()
    {
        Head = NULL;
    }
    ~stack()
    {
        if(Head != NULL)
            delete Head;
    }
    void remove();
    void display();
    void insert(T data);
    friend class iterate;
	//To find the position of the object
    iterate begin();
	/*
	{
		return iterate(*this);
	} 
	*/
};


template <class T>
iterate stack<T>::begin()
{
    return iterate(*this);
} 

template <class T>
void stack<T>::insert(T data)
{
        if(size != asize){
        std::cout << "\n\nInsert:" << data << "\n";;
        struct node *temp =new node();
        temp->data = data;
        
        size++;
        if(Head == NULL){
            temp->next = NULL;
            Head = temp;
            return;
        }else{
            temp->next = Head;
            Head = temp;
            return;
        }
    } else {
        std::cout << "Stack is full\n";
    }
}

template <class T>
void stack<T>::remove()
{

    std::cout << "\n\nRemove:\n";
    if(Head == NULL){
        std::cout << "Stack empty!, removal not possible!\n";
        return;
    } else {
        struct node *temp = Head;
        size--;
        if(temp->next == NULL){
            std::cout << "The data removed: " << temp->data << "\n";
            delete temp;
            Head = NULL;
            return;
        } else {
            struct node *temp1 = temp->next;
            Head = temp1;
            std::cout << "The data removed: " << temp->data << "\n";
            delete temp;
            return;
        }
    }
}

/*
template <class T>
void stack<T>::display()
{
    std::cout << "\n\nDisplay:\n";
    if(Head == NULL){
        std::cout << "The stack is empty\n";
        return ;
    } else {
        struct node* temp = Head;
        while(temp != NULL){
            std::cout << temp->data;
            if(temp->next != NULL)
                std::cout << "\n       |\n       v\n ";
            temp = temp->next;
        }
        std::cout << "\n";
        return;
    }
}
*/


int main()
{
    std::cout << "Enter the size of the stack\n";
    std::cin >> asize;

    stack<student> ob1;
    
    student s1("Kumar", 1999);
    student s2("Arjun", 2000);
    student s3("John", 2001);
    student s4("Sasuke", 2002);
    student s5("test", 1986);

    //ob1.display();
	
    ob1.insert(s1);
    ob1.insert(s2);
    ob1.insert(s3);
    ob1.insert(s4);
    ob1.insert(s5);
    //ob1.display();
    iterate<stack> it = ob1.begin();
	while(it.check())
	{
		std::cout << it.getData() << std::endl;
		it++;
	}
	ob1.remove();
    
	it = ob1.begin();
	while(it.check())
	{
		std::cout << it.getData() << std::endl;
		it++;
	}
    //ob1.display();

    return 0;
}
