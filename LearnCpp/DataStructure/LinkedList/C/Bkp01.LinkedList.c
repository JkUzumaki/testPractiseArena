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
//void insert_end(int val);
//void insert_pos(int val);

// Remove
void remove_front();
//int remove_end(int val);
//int remove_pos(int val);

// Display
void display();

int main()
{	
	insert_front();
	insert_front();
	insert_front();
	
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
