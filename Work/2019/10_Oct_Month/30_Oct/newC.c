#include<stdio.h>
#pragma pack(1)
struct foo
{
	int a;
	int b;
	char c[10];
}obj;

int main()
{
	struct foo *t = NULL;
        t=t+1;
	struct foo *t1 = t+1;
	//int diff = (int*)t1 - (int*) t;
	//int diff = (char*) t1 - (char*) t;
	printf("diff is %d\n",t);
	return 0;
}
