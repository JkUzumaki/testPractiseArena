#include<stdio.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int a = 10;
	int b = 20;
	printf("a: %d\tb: %d\n",a,b);
	swap(&a, &b);
	printf("a: %d\tb: %d\n",a,b);
	return 0;
}
