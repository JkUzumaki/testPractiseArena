#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *Head=NULL;

void add(int data)
{
	//Created a node and allocated the memory and assigned data
	struct Node *temp =  malloc(sizeof(struct Node));
	temp->data = data;
	// Assign the value of hd 
	temp->next = Head;
	Head = temp;
}

void display()
{
	//Assign the value to the temp
	struct Node *temp = Head;
	printf("Printing the queue\n");
	while(temp){
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int delete()
{
 	int flg = 0;
	struct Node *temp;
	struct Node *temp1;
	temp = Head;
	temp1 = temp->next;
	if(temp == NULL){
		return 0;
	}
	if(temp->next == NULL){
		flg = temp->data;
		free(temp);
		return flg;
	}
	while(temp1->next != NULL){
		temp = temp->next;
		temp1 = temp1->next;
	}
	flg = temp1->data;
	temp->next=NULL;
	free(temp1);
	return flg;
}

int main()
{
	//Allocate a memory for new node
	int v;
	// Send the address of the node as parameter
	add( 10);
	add( 20);
	add( 30);
	add( 40);
	add( 50);
	display();
	v = delete();
	printf("The deleted data %d\n",v);
	display();	
	return 0;
}
