#include<iostream>

//Class Start
class SLL
{
public:
	int data;
	SLL* next;
	SLL()
	{}
	//Insert at begin
	void insert_begin();
	//Delete at end
	void delete_end();
	//Display
	void display();
//---------------------------
	//Insert at specific position
	//Insert at end
	//Delete at specific position
	//Delete at end
	//Display
//---------------------------
};
//Class End
SLL* Head = new SLL();
void SLL::delete_end()
{
	if(Head == NULL){
		std::cout << "SLL is empty, delete at end cannot be performed\n";
		return ;
	}else{
		SLL* curr = new SLL();
		SLL* nxt = new SLL();
		curr = Head;
		nxt = curr->next;
		while(nxt){
			nxt = nxt->next;
			curr = curr->next;
		}
		std::cout << "The deleted node contains " << nxt->data;
		delete nxt;
		curr->next = NULL;
	}
}

void SLL::insert_begin()
{
	SLL* node = new SLL();
	if(node == NULL){
		std::cout << "memory not allocated for node\n";
		exit(0);
	}else{
		std::cout << "Enter the data\n";
		std::cin >> node->data;
		node->next = NULL;
	}
	if(Head == NULL){	
		Head = node;
	}else{
		node->next = Head;
		Head = node;
	}
}

void SLL::display()
{
	SLL* curr = new SLL();
	if(curr){
		std::cout << "Display\n\n";
		curr = Head;
		while(curr){
			std::cout << " curr "<< curr->data << " ";
			curr= curr->next;
		}
		std::cout << std::endl;
	}else{
		std::cout << "node cannot be created so traverse is not possible\n";
		exit(0);
	}
	delete curr;
}

int main()
{
	SLL sObj;
	//Head = NULL;
	std::cout << "-------------------------------------------------------------\nSingle Linked List\n\n";
	int flag = 1;
	int choice = 0;
	while(flag == 1){
		std::cout << "Enter the required option from below\n";
		std::cout << "1. Insert at begin\n2. Delete at end\n3. Display\n4. Exit\n";
		std::cin >> choice;
		switch(choice){
			case 1:
				sObj.insert_begin();
				break;
			case 2:
				sObj.delete_end();
				break;
			case 3:
				sObj.display();
				break;
			case 4:
				flag = 0;
				break;
			default:
				std::cout << "Incorrect entry..........................\n";	
		}
	}
	delete Head;
	return 0;	
}
