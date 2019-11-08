#include<iostream>
#include<set>
#include<string>

class Message
{
public:
	std::string msgContent;
	std::string sentBy;
	std::string receivedBy;
	Message(std::string sent, std::string rcv, std::string msg): 
		msgContent(msg), sentBy(sent), receivedBy(rcv)
		{}
	friend std::ostream& operator << (std::ostream& os, const Message& obj);
};

std::ostream& operator<<(std::ostream& os, const Message& obj)
{
	os << obj.sentBy << " :: " << obj.msgContent << " :: " << obj.receivedBy << std::endl;
	return os;
}

class MessageUserComparator
{
	std::string userName;
public:
	MessageUserComparator(std::string Name):userName(Name){}
	bool operator()(const Message& msg1, const Message& msg2) const
	{
		if(msg1.sentBy < msg2.sentBy)
			return true;
		else
			return false;
	}	
};

int main()
{
	Message msg1("usr_1", "usr_2", "Hello usr 2");
	Message msg2("usr_2", "usr_3", "Hello usr 3");
	Message msg3("usr_3", "usr_1", "Hello usr 1");

	//std::set<Message> setMsg;
	std::set<Message, MessageUserComparator> setMsg(MessageUserComparator("usr_1"));
	setMsg.insert(msg1);
	setMsg.insert(msg2);
	setMsg.insert(msg3);
	//std::set<Message>::iterator it;
	std::set<Message>::iterator it;
	for(it = setMsg.begin(); it != setMsg.end(); it++){
		//std::cout << *(it.sentBy) << " " << *(it.receivedBy) << " " << *(msgContent) << std::endl;
		std::cout << *it ;
	}
	std::cout << std::endl;
	return 0;
}



