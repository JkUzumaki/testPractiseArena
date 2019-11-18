#include <iostream>
#include <forward_list>
#include <iterator>
#include <algorithm>
using namespace std;

int main () {

    forward_list<int> list1 = { 10, 20, 10, 45, 45, 50, 25 };
    forward_list<int> list2 = { 20, 35, 27, 15, 100, 85, 12, 15 };

    cout << "\nFirst list before sorting ..." << endl;
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl; 

    cout << "\nSecond list before sorting ..." << endl;
    copy ( list2.begin(), list2.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl;

    list1.sort();
    list2.sort();

    cout << "\nFirst list after sorting ..." << endl;
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl; 

    cout << "\nSecond list after sorting ..." << endl;
    copy ( list2.begin(), list2.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl;    


    list1.merge ( list2 );

    cout << "\nMerged list ..." << endl;
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
/*
    cout << "\nlist 2 after merging\n";
    copy ( list2.begin(), list2.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl;
*/    
    cout << "\nMerged list after removing duplicates ..." << endl;
    list1.unique(); 
    copy ( list1.begin(), list1.end(), ostream_iterator<int>(cout, "\t") );
    cout << endl;
    return 0;
}
