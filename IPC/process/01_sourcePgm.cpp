#include<iostream>
#include<unistd.h>
#include<cstring>
#include<cstdlib>
using namespace std;

char *cptr = "Hello World\n";
char buffer1[25];

int main()
{
	void showit(char *);
	int i = 0;
	strcpy(buffer1, "A demonstration\n");
	write(1, buffer1, strlen(buffer1)+1);
	for(; i < 3; i++)
		showit(cptr);
	return 0;
}

void showit(char *p)
{
	char *buffer2;
	buffer2 = new char[ strlen(p) + 1];
	strcpy(buffer2, p);
	cout << buffer2;
	delete[] buffer2;
}
