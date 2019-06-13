#include<iostream>
#include<set>
#include<string>

class Message
{
public:
	std::string m_MsgContent;
	std::string m_sentBy;
	std::string m_recivedBy;

	Message(std::string sentBy, std::string recBy, std::string msg):
	m_MsgContent(msg), m_sentBy(sentBy), m_recivedBy(recBy){}

	bool operator< (const Message &mObj) const
	{
		std::string rightStr = mObj.m_MsgContent+ mObj.m_sentBy + mObj.m_recivedBy;
		std::string leftStr = this->m_MsgContent + this->m_sentBy + this->m_recivedBy;
		return (leftStr < rightStr);
	}
	friend std::ostream& operator<<(std::ostream& os, const Message& obj);
};

class MessageUserComparator
{
	std::string m_userName;
public:
	MessageUserComparator(std::string userName) :
	m_userName(userName)
	{}
	bool operator() (const Message& msg1, const Message& msg2) const
	{
		if(msg1.m_sentBy < msg2.m_sentBy )
			return true;
		else
			return false;
	}
};

std::ostream& operator<<(std::ostream& os, const Message& obj)
{
	os << obj.m_sentBy << " :: " << obj.m_MsgContent << " :: " << obj.m_recivedBy << std::endl;
	return os;
}

int main()
{
	std::set<Message> setOfMsgs;

	Message msg1("usr_1", "Hello", "usr_2");
	Message msg2("usr_1", "Hello", "usr_3");
	Message msg3("usr_3", "Hello", "usr_1");
	Message msg4("usr_1", "Hello", "usr_3");
	
	std::cout<<"set that contains the messages sent by user - user_1"<<std::endl;
	std::set<Message, MessageUserComparator> setOfMsgs_1(MessageUserComparator("usr_3"));
	setOfMsgs_1.insert(msg1);
	setOfMsgs_1.insert(msg2);
	setOfMsgs_1.insert(msg3);
	setOfMsgs_1.insert(msg4);
	
	for(std::set<Message>::iterator it = setOfMsgs_1.begin(); it != setOfMsgs_1.end(); it++)
		std::cout << *it  ;	
	return 0;
}
