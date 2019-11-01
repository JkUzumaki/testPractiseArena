#include<iostream>
#include<stdlib.h>

class Stack
{
	int top;
	int size;
	int *arr;
public:	
	Stack(int total){
		top = -1;
		size = total;
		arr = new int[size];
		for(int i = 0; i < size; i++){
			arr[i] = 0;
		}
	}
	~Stack(){
		delete [] arr;
	}
	void push();
	void pop();
	void display();
	bool isFull();
	bool isEmpty();
	void clearScrn();
};

bool Stack::isFull()
{
	if(top == (size-1))
		return true;
	else
		return false;
}

bool Stack::isEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}

void Stack::push()
{
	if(!isFull()){
		int data = 0;
		std::cout << "Enter the value to be pushed\n";
		std::cin >> data;
		top++;
		arr[top] = data;
		std::cout << "Data is inserted in the stack " << data << std::endl;
	}else{
		std::cout << "Stack Overflow, stack is full\n";
	}
}

void Stack::pop()
{
	if(isEmpty())
		std::cout << "Stack Underflow, stack is empty\n";
	else{
		std::cout << "Element deleted from stack : " << arr[top] << std::endl;
		arr[top] = 0;
		top--;
	}
}

void Stack::display()
{
	if(isEmpty())
		std::cout << "Stack is empty\n";
	else{
		std::cout << "Data in stack\n";
		for(int i = top; i >= 0; i--)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	return;	
}

void Stack::clearScrn()
{
	system("clear");
}

int main()
{
	int flag = 0;
	int option = 0;
	int size = 0;
	std::cout << "Enter the size for the stack\n";
	std::cin >> size;
	Stack sObj(size);
	while(1){
		std::cout << "\n\n-----------------------------------------------\n";
		std::cout << "Enter the relevant choice\n";
		std::cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n5. Clear Screen\n\n";
		std::cin >> option;
		switch(option){
			case 1:
				sObj.push();
				break;
			case 2:
				sObj.pop();
				break;
			case 3:
				sObj.display();
				break;
			case 4:
				flag = 1;
				break;
			case 5:
				sObj.clearScrn();
				break;
			default:
				std::cout << "Incorrect entry ....., try again\n";
		}
		if(flag == 1){
			std::cout << "Program terminated\n";
			break;
		}
	}
	return 0;
}
