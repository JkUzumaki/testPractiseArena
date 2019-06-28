#include <stdio.h>
#include <stdlib.h>

//Global Node
struct node
{
	int data;
	struct node *next;
};
struct node *Head = NULL;
// Insert
void insert_front();
void insert_end();
void insert_pos();

// Remove
void remove_front();
void remove_end();
void remove_pos();

// Display
void display();

int main()
{	
	insert_front();
	insert_front();
	insert_front();
	insert_pos();
	insert_end();
	display();
	//remove_pos();
	display();
	remove_front();
	display();
}

void insert_front()
{
	printf("\nInside insert function\n");
	int val = 0;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d", &val);
	temp->data = val;
	if(Head == NULL){
		temp->next = NULL;
		Head = temp;
		return;
	}else{
		temp->next = Head;
		Head = temp;
		return;
	}
}

void insert_end()
{
	printf("\nInside the insert at end function\n");
	int val = 0;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d", &val);
	temp->data = val;
	if(Head == NULL){
		temp->next = NULL;
		Head = temp;
		return;
	}else{
		struct node *temp1 = Head;
		while(temp1->next != NULL){
			temp1 = temp1->next;
		}
		temp1->next = temp;
		temp->next = NULL;
		return;
	}
}

void insert_pos()
{
/*
	printf("Inside the insert at specific position fucntion\n");
	int pos = 0;
	int Tpos = 0;
	int val = 0;
	struct node *temp1 = Head;
	while(temp1 != NULL){
		Tpos++;
		temp1 = temp1->next;
	}
	
	printf("The avaliable number of nodes %d\n", Tpos);
	printf("Enter the position to insert the node\n");
	scanf("%d", &pos);
	if(pos > Tpos || pos < 0){
		printf("The position is invalid %d\n", Tpos);
		printf("Node insertion failed\n");
		return;
	}else{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter the value to be inserted\n");
		scanf("%d", &val);
		temp->data = val;
		temp->next = NULL;
		
		temp1 = Head;
		int i= 1;
		struct node* temp2 = temp1->next;
		while((pos-1) > i){
			temp2 = temp2->next;
			temp1 = temp1->next;
			i++;
		}
		temp1->next = temp;
		temp->next = temp2;
		return;
	}
*/

	printf("Inside the insert at specific position function\n");
	int pos = 0;
	int count = 1;
	int val = 0;
	printf("Enter the position number to insert the node:\n");
	scanf("%d", &pos);
	
	struct node *temp1 = Head;
	struct node *temp2 = temp1->next;
	while(temp2->next != NULL){
		count++;
		if(count == pos)
			break;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	if(pos > count){
		printf("The position entered is out of range\n");
		return;
	}
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d", &val);
	temp->data = val;

	temp1->next = temp;
	temp->next = temp2;
	return;
}


void remove_pos()
{
	printf("Inside the remove at specific position function\n");
	int pos = 0;
	int Tpos = 0;
	int val = 0;
	
	struct node *temp = Head;
	while(temp != NULL){
		Tpos++;
		temp=temp->next;
	}

	printf("The available number of nodes %d\n", Tpos);
	printf("Enter the position to delete the node\n");
	scanf("%d", &pos);
	if(pos > Tpos || pos < 0){
		printf("The position is invalid %d\n Node deletion failed\n", pos);
		return;
	}else{
		temp=Head;
		int i = 1;
		struct node *temp1;
		struct node *temp2;
		//if(temp->next != NULL)
			temp1 = temp->next;
		//if(temp1->next != NULL)	
			temp2 = temp1->next;
		while(pos > i){
			temp = temp->next;
			temp1 = temp1->next;
			
		}
		printf("The deleted node contains the value %d", temp1->data);
		temp->next=temp1->next;
		free(temp1);
		return;
	}
}

void remove_front()
{
	printf("\nInside remove function\n");
	if(Head == NULL){
		printf("The list is empty, removal is not possible\n");
		return;
	}else{
		struct node *temp = Head;
		Head = temp->next;
		printf("The data is deleted %d\n", temp->data);
		free(temp);
		return;		
	}
}

void remove_end()
{
	printf("\nInside the remove at end function\n");
	if(Head == NULL){
		printf("The lsit is empty, removal at end is not possible\n");
		return;
	} else {
		struct node *temp = Head;
		struct node *temp1 = temp->next;
		while(temp1->next != NULL){
			temp = temp->next;
			temp1 = temp1->next;
		}
		printf("The data %d is deleted\n", temp1->data);
		temp->next = NULL;
		free(temp1);
		return;
	}
}

void display()
{
	printf("\nDisplay:\n");
	if(Head == NULL){
		printf("The list is empty, not data to be displayed\n");
		return;
	}else{
		struct node *temp = Head;
		while(temp != NULL){
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}	
}
