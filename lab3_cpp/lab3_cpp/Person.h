#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class Person {

public:
	std::string name;
	std::string address;

	Person();

	Person(std::string name, std::string address);

	virtual void Print();

	virtual ~Person();

};

#endif
