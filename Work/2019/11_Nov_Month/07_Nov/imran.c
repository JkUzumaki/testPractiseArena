#include <string.h>

#include <stdio.h>

 

char s1[] = "2165-KODEESWARAN-1234-GAUTHAM-5634-SELVA-4321";

char ptr[10],*st_ptr,*end_ptr;

 

int i=0,j=0,count=0;

 

int main()

{

    printf("Initial array:\n");

    printf("%s\n", s1);

 

    while(s1[i] != '\0')

    {

        if((s1[i]>='0')&&(s1[i]<='9'))

        {

            st_ptr=&s1[i];

        }

        while((s1[i]>='0')&&(s1[i]<='9'))

        {

            end_ptr=&s1[i];

            ptr[j]=s1[i];

            j++;

            i++;

           // printf("%d\n", count);

        }

                                ptr[j+1] = '\0';

                                count=strlen(ptr);

        for(int k=0;k<(count/2);k++)

        {

            char temp=*(st_ptr+k);

            *(st_ptr+k)=*(end_ptr-k);

            *(end_ptr-k)=temp;

        }

        j=0;

        count=0;

        i++;

    }

 

    printf("Final array:\n");

    printf("%s\n", s1);

 

    return 0;

}

 
