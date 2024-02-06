#ifndef PERSONWITHPHONE_H
#define PERSONWITHPHONE_H
#endif
#include <string>
#include "Person.h"


class PersonWithPhone : public Person 
{
public:
	std::string number;

	PersonWithPhone(std::string name, std::string address, std::string number);
	void Print();
	virtual ~PersonWithPhone();


	
};