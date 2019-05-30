#include <iostream>
using namespace std;
 
class Distance {
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
   public:
      // required constructors
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      // method to display distance
      void displayDistance() {
         cout << "F: " << feet << " I:" << inches <<endl;
      }
      // overloaded minus (-) operator
      Distance operator- () {
         feet = -feet;
         inches = -inches;
         return Distance(feet, inches);
      }
      // overloaded < operator
      bool operator <(const Distance& d) {
         if(feet < d.feet) {
            return true;
         }
         if(feet == d.feet && inches < d.inches) {
            return true;
         }
         return false;
      }

    //overload == operator
	bool operator== (const Distance& d){
	  if(feet == d.feet){
	  	if(inches == d.inches)
		    return true;
	  } else{
		return false;
	  }
	}
};
 
int main() {
   Distance D1(11, 10), D2(5, 11);
   Distance D3(10, 4), D4(10, 4);
   Distance D5(10, 4), D6(1, 4);
 
   if( D1 < D2 ) {
      cout << "D1 is less than D2 " << endl;
   } else {
      cout << "D2 is less than D1 " << endl;
   }
   if(D3 == D4){
	cout << "D3 is equal to D4\n";
   }else{
	cout << "D3 is not equal to D4\n";
   }
   if(D5 == D6){
	cout << "D5 is equal to D6\n";
   }else{
	cout << "D5 is not equal to D6\n";
   }
   return 0;
}
