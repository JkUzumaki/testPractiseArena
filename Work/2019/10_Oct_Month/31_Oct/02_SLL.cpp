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
	SLL* insert_begin(SLL* Head);
	//Delete at end
	SLL* delete_end(SLL* Head);
	//Display
	void display(SLL* Head);
//---------------------------
	//Insert at specific position
	//Insert at end
	//Delete at specific position
	//Delete at end
	//Display
//---------------------------
};
//Class End
SLL* SLL::delete_end(SLL* Head)
{
	if(Head == NULL){
		std::cout << "SLL is empty, delete at end cannot be performed\n";
	}else if(Head->next == NULL){
		SLL* curr = new SLL();
		curr = Head;
		std::cout << "The deleted node contains " << curr->data << std::endl;
		delete curr;
		Head = NULL;
	}else{
		SLL* curr = new SLL();
		SLL* nxt = new SLL();
		curr = Head;
		nxt = curr->next;
		while(nxt->next){
			nxt = nxt->next;
			curr = curr->next;
		}
		std::cout << "The deleted node contains " << nxt->data << std::endl;
		delete nxt;
		curr->next = NULL;
	}
	return Head;
}

SLL* SLL::insert_begin(SLL* Head)
{
	SLL* node = new SLL();
	if(node == NULL){
		std::cout << "memory not allocated for node\n";
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
	return Head;
}

void SLL::display(SLL* Head)
{
	SLL* curr = new SLL();
	if(curr){
		std::cout << "Display\n\n";
		curr = Head;
		if(curr == NULL){
			std::cout << "The SLL is empty\n";
			return;
		}
		while(curr){
			std::cout << curr->data << " ";
			curr= curr->next;
		}
		std::cout << std::endl;
	}else{
		std::cout << "node cannot be created so traverse is not possible\n";
	}
	delete curr;
}

int main()
{
	SLL sObj;
	SLL* Head = new SLL();
	Head = NULL;
	std::cout << "-------------------------------------------------------------\nSingle Linked List\n\n";
	int flag = 1;
	int choice = 0;
	while(flag == 1){
		std::cout << "------------------------------------------------\n\nEnter the required option from below\n";
		std::cout << "1. Insert at begin\n2. Delete at end\n3. Display\n4. Exit\n";
		std::cin >> choice;
		switch(choice){
			case 1:
				Head = sObj.insert_begin(Head);
				break;
			case 2:
				Head = sObj.delete_end(Head);
				break;
			case 3:
				sObj.display(Head);
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

