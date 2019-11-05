#include<iostream>

//Class Start
class DLL
{
public:
	int data;
	DLL* next;
	DLL* prev;
	DLL() {}
	//Insert at begin
	DLL* insert_begin(DLL*);
	//Delete at end
	DLL* delete_end(DLL*);
	//Display
	void Fwd_display(DLL*);
	//Display
	void Rev_display();
	//Insert at specific position
	DLL* insert_pos(DLL*);
	//Insert at end
	DLL* insert_end(DLL*);
	//Delete at specific position
	DLL* delete_pos(DLL*);
	//Delete at end
	DLL* delete_begin(DLL*);
};
//Class End

//To monitor the tail region
DLL* Tail = NULL;

// Delete_position
DLL* DLL::delete_pos(DLL* Head)
{
	DLL* node = new DLL();
	DLL* curr = new DLL();
	DLL* prev = new DLL();
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
				prev = curr;
				curr = curr->next;	
			}
			prev->next = curr->next;
			std::cout << "The deleted data " << curr->data << " at position " << pos << std::endl;
			delete curr;
			return Head;
		}
	}
}

// Delete_begin
DLL* DLL::delete_begin(DLL* Head)
{
	if(Head == NULL){
		std::cout << "DLL is empty, delete at begin cannot be performed\n";
	}else if(Head->next == NULL){
		DLL* curr = new DLL();
		curr = Head;
		std::cout << "The deleted node contains " << curr->data << std::endl;
		delete curr;
		Head = NULL;
	}else{
		DLL* curr = new DLL();
		curr = Head;
		Head = curr->next;
		std::cout << "The deleted node contains " << curr->data << std::endl;
		delete curr;
	}
	return Head; 	
}

// Delete_end
DLL* DLL::delete_end(DLL* Head)
{
	if(Head == NULL){
		std::cout << "DLL is empty, delete at end cannot be performed\n";
	}else if(Head->next == NULL){
		DLL* curr = new DLL();
		curr = Head;
		std::cout << "The deleted node contains " << curr->data << std::endl;
		delete curr;
		Head = NULL;
	}else{
		DLL* curr = new DLL();
		DLL* nxt = new DLL();
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

// Insert_begin DONE
DLL* DLL::insert_begin(DLL* Head)
{
	DLL* node = new DLL();
	if(node == NULL){
		std::cout << "Memory not allocated for node\n";
	}else{
		std::cout << "Enter the data\n";
		std::cin >> node->data;
		node->next = NULL;
		node->prev = NULL;
	}
	if(Head == NULL){	
		Head = node;
		Tail = node;
	}else{
		node->next = Head;
		Head = node;
	}
	return Head;
}

// Insert_end DONE
DLL* DLL::insert_end(DLL* Head)
{
	DLL* node = new DLL();
	if(node == NULL)
		std::cout << "Memory not allocated for node\n";
	else{
		std::cout << "Enter the data\n";
		std::cin >> node->data;
		node->next = NULL;
		node->prev = NULL;	
	}
	if(Head == NULL){}
		Head = node;
		Tail = node;
	}else{
		DLL* curr = new DLL();
		DLL* prev = new DLL();
		curr = Head;
		while(curr->next){
			prev = curr;
			curr = curr->next;
			curr->prev = prev;
		}
		curr->next = node;
		node->prev = curr;
		Tail = node;
	}
	return Head;
}

DLL* DLL::insert_pos(DLL* Head)
{
	DLL* node = new DLL();
	DLL* curr = new DLL();
	DLL* prev = new DLL();
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
				prev = curr;
				curr = curr->next;
			}
			prev->next = node;
			node->prev = prev;
			node->next = curr;
			curr->prev = node;
			return Head;
		}
	}
}

void DLL::Fwd_display(DLL* Head)
{
	DLL* curr = new DLL();
	if(curr){
		std::cout << "Display\n\n";
		curr = Head;
		if(curr == NULL){
			std::cout << "The DLL is empty\n";
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
void DLL::Rev_display()
{
	DLL* curr = new DLL();
	if(curr){
		std::cout << "Display\n\n";
		curr = Tail;
		if(curr == NULL){
			std::cout << "The DLL is empty\n";
			return;
		}
		while(curr){
			std::cout << curr->data << " ";
			curr= curr->prev;
		}
		std::cout << std::endl;
	}else{
		std::cout << "node cannot be created so traverse is not possible\n";
	}
	delete curr;
}
int main()
{
	DLL sObj;
	DLL* Head = new DLL();
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
				sObj.Fwd_display(Head);
				break;
			case 8:
				sObj.Rev_display();
				break;
			case 9:
				flag = 0;
				break;
			default:
				std::cout << "Incorrect entry..........................\n";	
		}
	}
	delete Head;
	return 0;	
}

