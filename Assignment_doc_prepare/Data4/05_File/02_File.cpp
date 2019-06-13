#include <iostream>
//#include <conio>
#include <fstream>

using namespace std;

int main()
{
	fstream st;
	st.open("textFile.txt", ios::out);
	if(!st)
		cout << "File creation failed" << endl;
	else{
		cout << "New file created\n";
		st.close();
	}
//	getch();
	return 0;
}
