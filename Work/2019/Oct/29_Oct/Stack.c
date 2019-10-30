#include<stdio.h>

void push(int& stack, int value);       // To insert a data over the top element
int pop();                              // To delete the top most element in the stack
int peek();                             // To view the top most element in the stack
void display();                         // To view all the elements in the stack

int top = 0;

struct stack{
    int value;
    struct stack *next;
};

int main()
{
    int size = 0;
    int data = 0;
    
    printf("Enter the size of the stack\n");
    scanf("%d", &size);
    struct stack *st = malloc(size * sizeof(struct stack));
    //int *start = &start;

    printf("Enter the value:\n");
    scanf("%d", &data);
    push(stack, data, start);

    return 0;
}

void push(int& stack, int value)
{
    
}