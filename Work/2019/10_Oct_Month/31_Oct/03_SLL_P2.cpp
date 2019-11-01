#include<iostream>

//Class Start
class SLL
{
public:
	int data;
	SLL* next;
	SLL() {}
	//Insert at begin
	SLL* insert_begin(SLL*);
	//Delete at end
	SLL* delete_end(SLL*);
	//Display
	void display(SLL*);
	//Insert at specific position
	SLL* insert_pos(SLL*);
	//Insert at end
	SLL* insert_end(SLL*);
	//Delete at specific position
	SLL* delete_pos(SLL*);
	//Delete at end
	SLL* delete_begin(SLL*);
};
//Class End
SLL* SLL::delete_pos(SLL* Head)
{
	SLL* node = new SLL();
	SLL* curr = new SLL();
	SLL* prv = new SLL();
	if(node == NULL && curr == NULL){
		std::cout << "memory not allocated for node\n";
	}else{
		int pos = 0, count = 0;
		std::cout << "Enter the position:\n";
		std::cin >> pos;
		if(pos <= 0){
			std::cout << "Position cannot be lesser than or equal to zero\n";
			return Head;
		}
		//First node
		if(pos == 1){
			Head = delete_begin(Head);
			return Head;
		}
		curr = Head;
		while(curr->next){
			curr= curr->next;
			count++;
		}
		count++;
		if(count < pos){//Check the range
			std::cout << "Cannot delete the node beyond the available " << count << std::endl;
			return Head;
		}else if(pos <= 0){
			std::cout << "Position should be greater than zero\n";
			return Head;
		}else if(count == pos){
			Head = delete_end(Head);
		}else{
			curr = Head;
			int flag = 0;
			int req = pos-1;
			
			for(int i = 0; i < req; i++){
				prv = curr;
				curr = curr->next;	
			}
			prv->next = curr->next;
			std::cout << "The deleted data " << curr->data << " at position " << pos << std::endl;
			delete curr;
			return Head;
		}
	}
}

SLL* SLL::delete_begin(SLL* Head)
{
	if(Head == NULL){
		std::cout << "SLL is empty, delete at begin cannot be performed\n";
	}else if(Head->next == NULL){
		SLL* curr = new SLL();
		curr = Head;
		std::cout << "The deleted node contains " << curr->data << std::endl;
		delete curr;
		Head = NULL;
	}else{
		SLL* curr = new SLL();
		curr = Head;
		Head = curr->next;
		std::cout << "The deleted node contains " << curr->data << std::endl;
		delete curr;
	}
	return Head; 	
}

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

SLL* SLL::insert_pos(SLL* Head)
{
	SLL* node = new SLL();
	SLL* curr = new SLL();
	SLL* prv = new SLL();
	if(node == NULL && curr == NULL){
		std::cout << "memory not allocated for node\n";
	}else{
		int pos = 0, count = 0;
		std::cout << "Enter the position:\n";
		std::cin >> pos;
		if(pos <= 0){
			std::cout << "Cannot insert in position lesser than or equal to zero\n";
			return Head;
		}
		//First node
		if(pos == 1){
			Head = insert_begin(Head);
			return Head;
		}
		curr = Head;
		if(Head == NULL){
			std::cout << "The STL is empty, inserting at specific position is not possible\n";
			return Head;
		}
		while(curr->next){
			curr= curr->next;
			count++;
		}
		count++;
		if(count < pos){//Check the range
			std::cout << "Cannot insert node beyond the available node " << count << std::endl;
			return Head;
		}else{//Login to insert at specific position
			int req = pos-1;
			curr = Head;
			std::cout << "Enter the value\n";
			std::cin >> node->data;
			for(int i = 0; i < req; i++){
				prv = curr;
				curr = curr->next;
			}
			prv->next = node;
			node->next = curr;
			return Head;
		}
	}
	
}

SLL* SLL::insert_end(SLL* Head)
{
	SLL* node = new SLL();
	if(node == NULL)
		std::cout << "Memory not allocated for node\n";
	else{
		std::cout << "Enter the data\n";
		std::cin >> node->data;
		node->next = NULL;	
	}
	if(Head == NULL)
		Head = node;
	else{
		SLL* curr = new SLL();
		curr = Head;
		while(curr->next)
			curr = curr->next;
		curr->next = node;
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
		std::cout << "1. Insert at begin\n2. Insert at end\n3. Insert at specific position\n4. Delete at begin\n5. Delete at specific position\n6. Delete at end\n7. Display\n8. Exit\n";
		std::cin >> choice;
		switch(choice){
			case 1:
				Head = sObj.insert_begin(Head);
				break;
			case 2:
				Head = sObj.insert_end(Head);
				break;
			case 3:
				Head = sObj.insert_pos(Head);
				break;
			case 4:
				Head = sObj.delete_begin(Head);
				break;
			case 5:
				Head = sObj.delete_pos(Head);
				break;
			case 6:
				Head = sObj.delete_end(Head);
				break;
			case 7:
				sObj.display(Head);
				break;
			case 8:
				flag = 0;
				break;
			default:
				std::cout << "Incorrect entry..........................\n";	
		}
	}
	delete Head;
	return 0;	
}

