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
	BST*** Test = &root;
	BST* Node = NULL;
	Node = getBST(value);
	
	if(**Test == NULL){
		//Empty BST fill
		std::cout << "First Node\n";
		*root = getBST(value);
	}else if((**Test)->data <= value){
		//Left node fill
		Insert((**Test)->left, value);
		//(**Test)->left = Node;
	}else if((**Test)->data > value){
		//Right node fill
		Insert((**Test)->right, value);
		//(**Test)->right = Node;
	}
	return **Test;
}

void print(BST* node){
	//std::cout << "Print fn\n";
	if(node == NULL)
	{
	//	std::cout << "BST is empty\n";
		return;
	}
	print(node->right);
	std::cout << node->data << " ";
	print(node->left);
}

int main()
{
	BST* root = NULL;
	root = Insert(&root, 20);
	root = Insert(&root, 10);
	root = Insert(&root, 30);
	root = Insert(&root, 35);
	root = Insert(&root, 5);
	print(root);
	std::cout << std::endl;
}
