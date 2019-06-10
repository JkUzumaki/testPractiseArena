#include<iostream>
#include<list>
#include<algorithm>
struct player
{
	int id;
	std::string name;
	player(int pId, std::string pName): id(pId), name(pName){}

	bool operator <(const player& obj) const
	{
		return id < obj.id;
	}
};

int main()
{
	std::list<player> lop = {player(22, "sid"),
				 player(3, "Laura"),
				 player(43, "riti"),
				 player(2, "lauran")
				};

	lop.sort();	

	for_each(lop.begin(), lop.end(), [] (const player &obj){
		std::cout << obj.id << " " << obj.name << std::endl;
	});
	return 0;
}
/*
For sort function we need to have a operator < being overloaded
else compilation cannot be procedded
*/
