#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct List
{
	int data;
	struct List *next;
};

void add(struct List **ptr,int data)
{

  struct List *temp=malloc(sizeof(struct List));
  temp->data=data;
  temp->next=*ptr;
  *ptr=temp; 
}

void display(struct List *ptr)
{

	struct List *temp=ptr;
	while(temp)
	{
	     printf("%d--->",temp->data);
	     temp=temp->next;
	}
	printf("\n");
}

int delete(struct List **ptr)
{

  struct List *temp=*ptr;
  *ptr=temp->next;
  int x=temp->data;
  free(temp);
  return x;
}

int main()
{

	struct List *Head=NULL;
	add(&Head,15);
	add(&Head,20);
	add(&Head,25);
	add(&Head,35);
	add(&Head,45);

	display(Head);
	printf("%d\n",delete(&Head));
	display(Head);
}
