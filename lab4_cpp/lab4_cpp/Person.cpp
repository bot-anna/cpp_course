#include <string>
#include <iostream>
#include "Person.h"


Person::Person()
{
}

Person::Person(std::string name, std::string address) : name(name), address(address)
{
}

void Person::Print()
{
	std::cout << "Name: " << name << "\nAddress: " << address << std::endl;
 }

/*for sorting on name*/

/*
bool Person::operator<(const Person& that)
{
	return this->name < that.name;
} */

/*for sorting on address*/
bool Person::operator<(const Person& that)
{
	return this->address> that.address;
} 

Person::~Person()
{
}

