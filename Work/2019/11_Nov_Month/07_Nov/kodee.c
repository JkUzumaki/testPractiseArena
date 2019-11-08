#include <string.h>
#include <stdio.h>
char s1[100] = "2165-KODEESWARAN-1234-GAUTHAM-5634-SELVA-4321"; 
//char s1[100] = "2165-KOD-1234-GU-5634-SELV-4321";
char ptr[10],*st_ptr,*end_ptr;

int i=0,j=0,count=0;
  
int main() 
{ 
    printf("Initial array:\n");
    printf("%s\n", s1);

    for(i=0;i<100;i++)
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
            count=strlen(ptr);
           // printf("%d\n", count);
        }
        for(int k=0;k<(count/2);k++)
        {
            char temp=*(st_ptr+k);
            *(st_ptr+k)=*(end_ptr-k);
            *(end_ptr-k)=temp;  
        }
        j=0;
        count=0;
    }
    
    printf("Final array:\n");
    printf("%s\n", s1);

    return 0; 
}
