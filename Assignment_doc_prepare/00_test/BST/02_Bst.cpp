#include<iostream>

//Fill the struct 
struct BST{
	int data;
	BST* left;
	BST* right;
};

//Create the new node
BST* getBST(int value)
{
	BST* Node = new BST();
	Node->data = value;
	Node->left = NULL;
	Node->right = NULL;
	return Node;
}

//Insert a new node
BST* Insert(BST** root, int value)
{
	BST* Node = NULL;
	if(*root == NULL){
		//Empty BST fill
		std::cout << "First Node\n";
		*root = getBST(value);
	}else if((*root)->data <= value){
		//Left node fill
		Node = getBST(value);
		//std::cout << "(*root)->data " << (*root)->data << " " << value << std::endl;	//For test
		(*root)->left = Node;
	}else if((*root)->data > value){
		//Right node fill
		Node = getBST(value);
		//std::cout << "(*root)->data " << (*root)->data << " " << value << std::endl;	//For test
		(*root)->right = Node;
	}
	return *root;
}

//Display the data in BST
void display(BST* root)
{
	//Fill the 
	if(root != NULL){
		std::cout << "Data: "<< root->data << "\n";
		std::cout << "Left address " << root->left << "\n";
		std::cout << "Right address " << root->right << "\n";		
	}else{
		std::cout << "The list is empty\n";
	}
}

int main()
{
	BST* root = NULL;
	root = Insert(&root, 20);
	root = Insert(&root, 10);
	root = Insert(&root, 30);
	display(root);
}
