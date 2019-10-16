#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
  int a = 10, b = 20;
  int *pa = &a;
  int *pb = &b;
  printf("a : %d\tb: %d\n",a, b);
  swap(&pa, &pb);
  printf("a : %d\tb: %d\n",a, b);
  return 0;
}
