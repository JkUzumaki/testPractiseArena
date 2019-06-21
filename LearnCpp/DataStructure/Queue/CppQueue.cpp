#include<iostream>
#include "student.h"
template <class T>
class queue
{
private:
	struct Node
	{
		T data;
		struct Node *next;
	};
	struct Node *Head;
public:
	queue()
	{
		Head = NULL;
	}
	void insert(T value);
	T remove();
	void display();
};

template <class T>
void queue<T>::insert(T value)
{
	Node *temp = new Node;
	temp->data = value;
	temp->next = Head;
	Head = temp;
}

template <class T>
void queue<T>::display()
{
	Node* temp = Head;
	while(temp){
		std::cout << temp->data << " -> " ;
		temp = temp->next;
	}
	std::cout << "\n";
}

template <class T>
T queue<T>::remove()
{
	T value;
	Node *temp = Head;
	Node *temp1;
	temp1 = temp->next;
	//if(temp == NULL)
	//	return ;
	if(temp->next == NULL){
		value = temp->data;
		delete temp;
		return value;
	}
	while(temp1->next != NULL){
		temp= temp->next;
		temp1 = temp1->next;
	}
	value = temp1->data;
	temp->next=NULL;
	delete temp1;
	return value;
}

int main()
{
/*	queue<int> obj;
	//Add data
	obj.insert(10);
	obj.insert(20);
	obj.insert(30);
	//Display
	obj.display();
	//Delete
	int rm = obj.remove();
	std::cout << "The removed data is " << rm << std::endl;
	//Display
	obj.display();
*/
       queue<student> ob1;
	student s1 ("ram", 2000);	
	student s2("prem", 2001);
	student s3("yash", 2002);
	student s4("dev", 1999);
	ob1.insert(s1);
	ob1.insert(s2);
	ob1.insert(s3);
	ob1.insert(s4);
	ob1.display();
	std::cout << "The deleted data " << ob1.remove() << std::endl;
	ob1.display();		
}
