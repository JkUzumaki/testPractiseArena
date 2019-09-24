#include<iostream>
#include<string>

class Worker{
public:
	std::string name;
};

class Student: public virtual Worker{
public:
	int studentId;
};

class Assistant: virtual public Worker{
public:
	int empId;
};

class StudentAssistant: public Student, public Assistant{};

