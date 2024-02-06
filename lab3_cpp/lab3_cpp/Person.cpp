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

Person::~Person()
{
	std::cout << "Destroying " << name << " with address " << address << " !!" << std::endl;
}

