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

std::ostream& operator<<(std::ostream& os, const Message& obj)
{
	os << obj.m_sentBy << " :: " << obj.m_MsgContent << " :: " << obj.m_recivedBy << std::endl;
	return os;
}

int main()
{
	std::set<Message> setMsg;

	Message msg1("usr_1", "Hello", "usr_2");
	Message msg2("usr_1", "Hello", "usr_3");
	Message msg3("usr_3", "Hello", "usr_1");
	Message msg4("usr_1", "Hello", "usr_3");

	setMsg.insert(msg1);	
	setMsg.insert(msg2);	
	setMsg.insert(msg3);	
	setMsg.insert(msg4);	

	for(std::set<Message>::iterator it = setMsg.begin(); it != setMsg.end(); it++)
	std::cout << *it  ;
	
	return 0;
}
