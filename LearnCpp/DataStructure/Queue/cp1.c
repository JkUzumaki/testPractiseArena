#include<stdio.h>

struct Node
{
	int data;
	struct Node *next;
};

void add(struct Node **hd, int data)
{
	//Created a node and allocated the memory and assigned data
	struct Node *temp =  malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	// Assign the value of hd 
	temp->next = *hd;
	*hd = temp;
}

void display(struct Node *hd)
{
	struct Node *temp = hd;
	while(temp){
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int main()
{
	//Allocate a memory for new node
	struct Node *Head = malloc(sizeof(struct Node));
	
	// Send the address of the node as parameter
	add(&Head, 10);
	add(&Head, 20);
	display(Head);
	return 0;
}
