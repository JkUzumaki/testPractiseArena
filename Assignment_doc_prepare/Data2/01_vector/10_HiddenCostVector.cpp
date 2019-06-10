#include<vector>
#include<iostream>

class Item 
{
public:
	static int m_ConstructorCalledCount;
	static int m_DestCalledCount;
	static int m_CopyConstructorCalledCount;

	Item() 	{					// constructor
	m_ConstructorCalledCount++;
	}

	~Item()	{					// destructor
	m_DestCalledCount++;
	}

	Item(const Item& obj) {				// copy constructor
	m_CopyConstructorCalledCount++;
	}

};

int Item::m_ConstructorCalledCount = 0;
int Item::m_CopyConstructorCalledCount = 0;
int Item::m_DestCalledCount = 0;

class ItemFactory
{
public:
	static std::vector<Item> getItemObjects(int count)	// static function
	{
		std::vector<Item> vecOfItems;
		vecOfItems.reserve(count);
		for (int var = 0; var < count; ++var) {
		vecOfItems.push_back(Item());
		}
		return vecOfItems;
	}
};

int main()
{
	int count = 10000;
	std::vector<Item> vecOfItems;
	vecOfItems = ItemFactory::getItemObjects(count);
	std::cout<<"Total Item Objects constructed = "<<(Item::m_ConstructorCalledCount + Item::m_CopyConstructorCalledCount)<<std::endl;
	std::cout<<"Constructor called  "<<Item::m_ConstructorCalledCount <<" times"<<std::endl;
	std::cout<<"Copy Constructor called  "<<Item::m_CopyConstructorCalledCount <<" times"<<std::endl;
	std::cout<<"Total Item Objects destructed = "<<Item::m_DestCalledCount<<std::endl<<std::endl;
	return 0;
}
