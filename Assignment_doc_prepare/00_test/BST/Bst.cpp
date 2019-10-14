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
	
	if(*root == NULL){
		//Empty BST fill
		std::cout << "First Node\n";
		*root = getBST(value);
	}else if((*root)->data <= value){
		//Left node fill
		while((**Test)->data){
			if((**Test)->data > value){
				(**Test)->right = Node;
				break;
			}
			**Test = (**Test)->left;
		}
		(**Test)->left = Node;
	}else if((*root)->data > value){
		//Right node fill
		//Node = getBST(value);
		//std::cout << "(*root)->data " << (*root)->data << " " << value << std::endl;	//For test
		(*root)->right = Node;
	}
	return *root;
}

//Display the data in BST
void display(BST* root)
{
	/*
	//Fill the 
	if(root != NULL){
		std::cout << "Data: "<< root->data << "\n";
		std::cout << "Left address " << root->left << "\n";
		std::cout << "Right address " << root->right << "\n";		
	}else{
		std::cout << "The list is empty\n";
	}
	*/
	while(root){
		std::cout << root->data << "\n";
		if(root->left != NULL){
			root = root->left;
			
		}
		//root = root->right;
		
	}
}

int main()
{
	BST* root = NULL;
	root = Insert(&root, 20);
	root = Insert(&root, 10);
	root = Insert(&root, 13);
	display(root);
}
