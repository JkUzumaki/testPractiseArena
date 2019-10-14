#include<iostream>

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* root = NULL;

Node* getNode(int data){
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void Insert(int value){
	//Empty tree
	if(root == NULL){
		root = getNode(value);
	}else if(value <= (root->data)){	// insert
		root->left = getNode(value);
	}else{					// insert
		root->right = getNode(value);
	}
}

void display(){
	std::cout << "In Display\n";
	if(root == NULL){
		std::cout << "The BST is empty\n\n";
	}else{
		Node *test = root;
		Node *Ltest = NULL;
		Node *Rtest = NULL;
		if(test->left != NULL)
			Node *Ltest = test->left;
		if(test->right != NULL)
			Node *Rtest = test->right;
	//	if((test != NULL) && (Ltest != NULL) && (Rtest != NULL)){	//CHECK
			std::cout << test->data << "\n\n";
			std::cout << Ltest->data << "\t\t" << Rtest->data << std::endl;	
		//}
	}
}

int main(){
	Insert(15);
	Insert(10);
	Insert(20);
	display();
}
