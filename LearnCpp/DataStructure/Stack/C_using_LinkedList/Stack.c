#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct List
{
	int data;
	struct List *next;
};

int add(struct List **ptr,int data, int size)
{
  int a = size;
  if(a != SIZE){
	  struct List *temp=malloc(sizeof(struct List));
	  temp->data=data;
	  temp->next=*ptr;
	  *ptr=temp; 
	  a = size +1;
	  return a;
  }else{
    printf("The stack is FULL\n");
    return a;
  }
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

int delete(struct List **ptr, int size)
{
  int a = size;
  if(a != 0){
  struct List *temp=*ptr;
  *ptr=temp->next;
  int x=size--;
  free(temp);
  return x;
  }
 else{
   printf("The stack is empty\n");
   return 0;
 }
}

int main()
{
	int size =0;
	struct List *Head=NULL;
	size = delete(&Head, size);
	size = add(&Head,15, size);
	size = add(&Head,20, size);
	size = add(&Head,25, size);
	size = add(&Head,35, size);
	size = add(&Head,45, size);
	display(Head);
	size = add(&Head,55, size);
	printf("The size of the stack %d ", size);
	size = delete(&Head, size);
	display(Head);
}
