#include<stdio.h>
#include<stdlib.h>
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
	//temp->next = NULL;
	// Assign the value of hd 
	temp->next = *hd;
	*hd = temp;
}

void display(struct Node *hd)
{
	//Assign the value to the temp
	struct Node *temp = hd;
	while(temp){
		printf("%d-->", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int delete(struct Node **hd)
{
 	int flg = 0;
	struct Node *temp;
	struct Node *temp1;
	temp = *hd;
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
	struct Node *Head= NULL;// = malloc(sizeof(struct Node));
	int v;
	// Send the address of the node as parameter
	add(&Head, 10);
	add(&Head, 20);
	add(&Head, 30);
	add(&Head, 40);
	add(&Head, 50);
	display(Head);
	v = delete(&Head);
	printf("The deleted data %d\n",v);
	display(Head);	
	return 0;
}
