#include<iostream>
#include<math.h>
#include<cmath>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<cstring>
#include<string.h>
using namespace std;

int main()
{
string  str,str2;
int stat;
int i,x=0,f=0;
int  y,z;
int count = 0;
char ch;

cout<<"enter your exp:";
getline(cin,str);
int str_size = str2.size()+1;
int p[2],res,pid;

if((pipe(p) < 0)) //Creates pipe
 exit(0);
pid = fork();

if(pid > 0)//parent
{
 write(p[1],&str,20);
 sleep(1);
 read(p[0], &res ,4);

 cout<<"\nThe parent value from child:\n\n"<<res;

}else{//Child
 cout << "Inside the child\n";
 read(p[0],&str2,20);
 cout << "Read expression : \n" << str2 << endl;
 i = 0;
 while(str2[i] != '\0'){
  if(str2[i] >= '0' && str2[i] <= '9'){
   //cout << "x inside while: " << x << endl;
   x = x * 10 + str2[i] - 48;
   i++;
   if(f == 0){
    count++; // for counting the number of digit of first number
   } 
  }
  else if(str2[i]>=37 && str2[i]<=47){
   ch = str2[i];
   i++;   
   f++;  
  }
 }
 cout << "x : " << x << endl;
 
 y = fmod(x,pow(10,count));
 z = x / pow(10,count);
 cout << "number 1 " << z << endl;
 cout << "number 2 " << y << endl;
 
 switch(ch){
  case '+'  :
   cout << "\naddition:";
   res = z+y;
   cout<<"\nresult:"<<res; 
   break;
  case '-' :
   cout << "\nDifference";
   res = z-y;
   cout<<"\n result: "<<res;
   break;
  case '*' :
   cout << "\nMultiplication";
   res =y*z;
   cout<<"\nresult:"<<res;
   break;
  case '/' :
   cout<<"\nDivision ";
   res =z/y;
   cout<<"\nresult"<<res;
   break;
  default :
   cout << "\n invalid  Choice.";
   break;
 }
 cout<<"\nchild value from parent :\n\n"<<res<<endl;
 write(p[1],&res,4);
}
 

return 0;
}

