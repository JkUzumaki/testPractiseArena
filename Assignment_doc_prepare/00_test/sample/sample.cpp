#include<stdio.h>

int main() {
    int i = 0, j = 1;
    if (j) {
        if (i) {
            return 1;
            j = 0;
        }
    }
	printf("operation completed\n");
    return 10;
}
