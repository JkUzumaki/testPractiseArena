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
	int option = 0;
	int flag = 0;
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
				insert_front();
				break;
			case 2:
				insert_pos();
				break;
			case 3:
				insert_end();
				break;
			case 4:
				remove_front();
				break;
			case 5:
				remove_pos();
				break;
			case 6:
				remove_end();
				break;
			case 7:
				display();
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
	printf("Inside the insert at specific position function\n");
	int pos = 0;
	int count = 1;
	int val = 0;
	printf("Enter the position number to insert the node:\n");
	scanf("%d", &pos);

	//When Head is NULL
	if(pos == 1 && Head == NULL){
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter the value to be inserted\n");
		scanf("%d", &val);
		temp->data = val;
		temp->next = NULL;
		Head = temp;
		return;
	}

	if(pos > 1 && Head == NULL){
		printf("The position entered is out of range\n");
		return;
	}

	struct node *temp1 = Head;
	struct node *temp2 = temp1->next;
	while(temp2->next != NULL){
		count++;
		if(count >= pos)
			break;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	int flg = 0;
	if(temp2->next == NULL ){
		if(count != 1){
			flg = 1;
		}
		count++;
	}
	if(pos > count){
		printf("The position entered is out of range\n");
		return;
	}
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted\n");
	scanf("%d", &val);
	temp->data = val;
	// Insert at first	
	if(pos == 1){
		temp->next = temp1;
		Head = temp;
		return;
	}
	// Insert at middle
	if(pos == count && flg == 0){
		temp1->next = temp;
		temp->next = temp2;
		return;
	}
	// Insert at end
	if(pos == count && flg == 1){
		temp2->next = temp;
		temp->next = NULL;
		return;
	}

}


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
