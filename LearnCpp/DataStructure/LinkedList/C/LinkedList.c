#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
// Insert
void insert_front(struct node **ptr);
void insert_end(struct node **ptr);
void insert_pos(struct node **ptr);

// Remove
void remove_front(struct node **ptr);
void remove_end(struct node **ptr);
void remove_pos(struct node **ptr);

// Display
void display(struct node **ptr);

int main()
{	
	int option = 0;
	int flag = 0;

	struct node *Head = NULL;
	while(1){
		printf("\n--------------------------------------------------\n");
		printf("Enter the required option to perform the operation:\n");
		printf("1. Insert front\n");
		printf("2. Insert position\n");
		printf("3. Insert end\n");
		printf("4. Remove front\n");
		printf("5. Remove position\n");
		printf("6. Remove end\n");
		printf("7. Display\n");
		printf("8. Exit\n");
		scanf("%d", &option);
		
		switch(option){
			case 1:
				insert_front(&Head);
				break;
			case 2:
				insert_pos(&Head);
				break;
			case 3:
				insert_end(&Head);
				break;
			case 4:
				remove_front(&Head);
				break;
			case 5:
				remove_pos(&Head);
				break;
			case 6:
				remove_end(&Head);
				break;
			case 7:
				display(&Head);
				break;
			case 8:
				flag = 1;
				break;
			default:
				printf("Incorrect entry, Please select a correct option\n");
		}
		if(flag == 1){
			printf("Process terminated\n");
			break;
		}
	}
}

void insert_front(struct node **ptr)
{
	printf("\nInside insert function\n");
	int val = 0;
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d", &val);
	temp->data = val;
	if(ptr == NULL){
		temp->next = NULL;
		ptr = temp;
		return;
	}else{
		temp->next = ptr;
		ptr = temp;
		return;
	}
}

void insert_end(struct node **ptr)
{
	printf("\nInside the insert at end function\n");
	int val = 0;
	struct node *temp = malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d", &(temp->data));
	//temp->data = val;
	struct node *temp1 = ptr;
	if(temp1->next == NULL){
		temp1->next = temp;
		temp->next = NULL;
	}else{
		while(temp1){
			temp1 = temp1->next;
		}	
		temp1->next = temp;
		temp->next = NULL;
	}
	return;
}

void insert_pos(struct node **ptr)
{
	printf("Inside the insert at specific position function\n");
	int pos = 0;
	int count = 2;
	int val = 0;
	printf("Enter the position number to insert the node:\n");
	scanf("%d", &pos);

	//When Head is NULL
	if(pos == 1 && ptr == NULL){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter the value to be inserted\n");
		scanf("%d", &val);
		temp->data = val;
		temp->next = NULL;
		ptr = temp;
		return;
	}

	if(pos > 1 && ptr == NULL){
		printf("The position entered is out of range\n");
		return;
	}
    
       struct node* temp1=ptr;
       struct node* temp2=temp1->next;
       while(temp2)
       {
           if(count==pos)
                break;
           else{
           temp1=temp1->next;
           temp2=temp2->next;
           count++;}
       }
       
      struct node* ptr1=malloc(sizeof(struct node));
      printf("enter the data\n");
      scanf("%d",&ptr1->data);

      ptr1->next=temp2;//temp1->next;
      temp1->next=ptr1;
}

void remove_pos(struct node **ptr)
{
	printf("Inside the remove at specific position function\n");
	if(ptr == NULL){
		printf("The list is empty and removal is not possible\n");
		return;
	}
	int pos = 0;
	int count = 2;
	printf("Enter the position to be removed\n");
	scanf("%d", &pos);
	struct node *temp = ptr;
	if(pos == 1 && temp->next == NULL){
		printf("The deleted element %d\n", temp->data);
		free(temp);
		ptr = NULL;
		return;
	}
	if(pos == 1){
		ptr = temp->next;
		printf("The deleted element %d\n", temp->data);
		free(temp);
		return;	
	}
	struct node *temp1 = temp->next;
	while(temp1){
		if(count == pos){
			break;
		}else{
			temp = temp->next;
			temp1 = temp1->next;
			count++;
		}
		
	}
	if(temp1->next != NULL){
		printf("The deletd data is %d\n", temp1->data);
		temp->next = temp1->next;
		free(temp1);
		return;
	}else{
		printf("The deletd data is %d\n", temp1->data);
		temp->next = NULL;
		free(temp1);
		return;
		
	}
}
/*
void remove_pos()
{
	printf("Inside the remove at specific position function\n");
	int pos = 0;
	int count = 1;
	printf("Enter the position number to remove the node:\n");
	scanf("%d", &pos);
	struct node *temp = Head;

	//Remove first	
	if(pos == 1){
		Head = temp->next;
		printf("The deleted data is %d\n", temp->data);
		free(temp);
		return;
	}
	struct node *temp1 = temp->next;

	while(temp1->next != NULL){
		count++;
		if(count >= pos)
			break;
		temp = temp->next;
		temp1 = temp1->next;
	}	

	int flg = 0;
	if(temp1->next == NULL){
		count++;
		flg = 1;
	}

	struct node *temp2 = temp1->next;
	//Remove middle
	if(flg == 0 && pos == count)
	{
		temp->next = temp2;
		printf("The deleted data is %d\n", temp1->data);
		free(temp1);
		return;	
	}
	//Remove end
	if(flg == 1 && pos == count){
		temp->next = NULL;
		printf("The deleted data is %d\n", temp1->data);
		free(temp1);
		return;
	}	
}
*/
void remove_front(struct node **ptr)
{
	printf("\nInside remove function\n");
	if(ptr == NULL){
		printf("The list is empty, removal is not possible\n");
		return;
	}else{
		struct node *temp = ptr;
		ptr = temp->next;
		printf("The data is deleted %d\n", temp->data);
		free(temp);
		return;		
	}
}

void remove_end(struct node **ptr)
{
	printf("\nInside the remove at end function\n");
	if(ptr == NULL){
		printf("The lsit is empty, removal at end is not possible\n");
		return;
	} else {
		struct node *temp = ptr;
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

void display(struct node **ptr)
{
	printf("\nDisplay:\n");
	if(ptr == NULL){
		printf("The list is empty, not data to be displayed\n");
		return;
	}else{
		struct node *temp = ptr;
		while(temp != NULL){
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}	
}
