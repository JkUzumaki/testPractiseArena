#include<stdio.h>
#define SIZE 5

int gSize = 0;
int gflag = 0;

struct List
{
	int data;
	struct List *next;
};

struct List *Head;
Head = NULL;

struct List *n;
List* create()
{
	struct List *n;
	int data = 0;
	
	n = (struct List*) malloc (sizeof(struct List))
	printf("Enter the data for the node\n");
	scanf("%d", &data);
	
	n->data = data;
	n->next = NULL;

	return n;
}



void add()
{
	//Check actual size
	if(gSize != SIZE){
		//Creation of node and get data
		node temp;
		temp = (node)malloc(sizeof(struct List));
		temp->next = NULL;

		
		
	}else{
		printf("Stack is Full\n");
	}
}

void delete()
{

}

void display()
{

}


int main()
{

	int choice = 0;
	while(1){
		printf("Enter the option:\n")
		printf("1. Add a node to stack\n");
		printf("2. Delete a node to stack\n");
		printf("3. Display the stack\n");
		printf("4. Exit the process\n");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				add();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				flag = 1;
				break;
			default:	
				printf("Incorrect entry, please enter a correct option\n");
		}
		if(gflag == 1)
			break;
	}
	return 0;
}
