#include<iostream>
#include<stdlib.h>

class Queue
{
	int front;
	int back;
	int size;
	int *arr;
public:
	Queue(int value){
		size = value;
		arr = new int [value];
		front = back = -1;
	}
	~Queue(){
		delete [] arr;
	}
	bool isFull();
	bool isEmpty();
	void enqueue();
	void dequeue();
	void display();
	void count();
};

bool Queue::isFull()
{
	//int cSize = back - front;
	if(back ==  size-1)
		return true;
	else
		return false;
}

bool Queue::isEmpty()
{
	if(back == -1 && front == -1)
		return true;
	else
		return false;
}

void Queue::enqueue()
{
	if(isFull()){
		std::cout << "Queue is full\n";
		return;
	}else if(front == -1 && back == -1){
		front++;
		back++;
		int data;
		std::cout << "Enter the value to be inserted\n";
		std::cin >> data;
		arr[front] = data;
	}else{
		back++;
		int data;
		std::cout << "Enter the value to be inserted\n";
		std::cin >> data;
		arr[back] = data;
	}
}

void Queue::dequeue()
{
	if(isEmpty()){
		std::cout << "The queue is empty\n";
		return;
	}else if(front == back){
		std::cout << "The element deleted " << arr[front] << std::endl;
		arr[front] = 0;
		front = -1;
		back = -1;
		return;
	}else{
		std::cout << "The element deleted " << arr[front] << std::endl;
	
		//Moving the elements forward the array in order to assess the elements easily
		for(int i = front; i < back; i++){	
			arr[i] = arr[i+1];
		}
		//Once we have moved the elements forward we will have excess element in the front and so we decrement it
		arr[back] = 0;
		back--;
		
		return;
	}
}

void Queue::display()
{
	if(isEmpty()){
		std::cout << "Queue is empty\n";
		return;
	}else{
		std::cout << "Elements in queue:\n";
		for(int i = back; i >= front; i --)
			std::cout << arr[i] << " ";
		std::cout << "\n";
	}
}

void Queue::count()
{
	if(isEmpty())
		std::cout << "The queue is empty\n";
	else
		std::cout << "The elements inside in the queue " << (back+1)-front << std::endl;
}

void clearScrn()
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
	Queue sObj(size);
	while(1){
		std::cout << "\n\n-----------------------------------------------\n";
		std::cout << "Enter the relevant choice\n";
		std::cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n5. Clear Screen\n6. count\n\n";
		std::cin >> option;
		switch(option){
			case 1:
				sObj.enqueue();
				break;
			case 2:
				sObj.dequeue();
				break;
			case 3:
				sObj.display();
				break;
			case 4:
				flag = 1;
				break;
			case 5:
				clearScrn();
				break;
			case 6:
				sObj.count();
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