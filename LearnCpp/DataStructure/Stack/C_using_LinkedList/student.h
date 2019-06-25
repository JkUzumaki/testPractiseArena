
#include<iostream>
#include<string>
class student
{
	std::string name;
	int year;
public:
	student(std::string str,int yr):name(str), year(yr)
 	{}
        student()
        {}
       friend  std::ostream& operator<<(std::ostream& os,const student &ob)
        {
           return os<<ob.name<<"  "<<ob.year;
        }
};
