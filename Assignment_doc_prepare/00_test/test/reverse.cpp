#include<iostream>

void reverse(char *s){
	int n = 0;
	std::cout << "Actual:\t";
	while(*(s+n) != '\0'){
		std::cout << *(s+n);
		n++;
	}
	std::cout << "\n\nAfter Reverse:\t";
	while(n != 0){
		std::cout << *(s+n);
		n--;
	}
	std::cout <<*s;
	std::cout << "\n";
	return;
}

int main()
{
	reverse("Hola Senorita");
	return 0;
}
