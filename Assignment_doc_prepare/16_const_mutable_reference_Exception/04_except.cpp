
#include <iostream> 
using namespace std; 
class exception1
{
 int errorno;
public:
	void display()
	{	
		cout << "Error no. " << errorno << endl;
	}
	exception1(int no):errorno(no)
	{}
}; 
int main() 
{ 
   int x = -1; 
  
   // Some code 
   cout << "Before try \n"; 
   try { 
      cout << "Inside try \n"; 
      if (x < 0) 
      { 
        exception1 ob(5);
         throw ob; 
         cout << "After throw (Never executed) \n"; 
      } 
   } 
   catch (exception1& ob1 ) {
      ob1.display(); 
      cout << "Exception Caught \n"; 
   } 
  
   cout << "After catch (Will be executed) \n"; 
   return 0; 
} 

