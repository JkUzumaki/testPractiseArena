#include<list>
#include<iostream>

struct Player
{
	int id;
	std::string name;
	
	Player(int pId, std::string pName):
		id(pId), name(pName){}
};

int main()
{
	std::list<Player> lop = {Player(22, "sid"),
				Player(3, "Laura"),
				Player(43, "riti"),
				Player(30, "Angel"),		
				Player(2, "Laura"),
				Player(10, "ten")
	};
	std::list<Player>::iterator it;
	for(it = lop.begin(); it!= lop.end(); it++){
		//int id = it->id;
		//std::string name = it->name;
		std::cout << it->id << "::" << it->name << std::endl;
	}
}
