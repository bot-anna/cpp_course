#include <string>
#include <iostream>
#include "PersonReg.h"
#include "Person.h"

PersonReg::PersonReg(int maxSize)
{
	persons = new Person[maxSize];
	this->maxSize = maxSize;
	i = 0;
}

bool PersonReg::add(const Person* const p)
{
	if (i < maxSize) 
	{
		persons[i] = *p;
		i++;
		return true;
	} 
	else
	{
		return false;
	}
}

bool PersonReg::addToTest(const std::string& name, const std::string& address)
{
	const Person* const p = new Person(name, address);
	bool success = add(p);
	delete p;
	return success;
}

void PersonReg::removeEntry(Person* ptr)
{
	for (Person* lptr = ptr; lptr != persons + i; lptr++) {
		*lptr = *(lptr + 1);
	}
	i--;
}
Person* PersonReg::searchName(const std::string& name) const
{
	for (Person* ptr = persons; ptr != persons + maxSize; ptr++)
	{
		if (ptr->name == name)
		{
			std::cout << "Found name: " << name << " Adress: ";
			return ptr;
		}
	}
	return nullptr;
}
void PersonReg::Print() const
{
	std::cout << "Printing registry:" << std::endl;
	for (Person* ptr = persons; ptr != persons + maxSize; ptr++)
	{
		ptr->Print();
	}
	std::cout << "\n\n";
}
void PersonReg::empty()
{	
	std::cout << "Emptying..\n\n";
	delete[] persons;
	persons = new Person[maxSize];
}

Person* PersonReg::freeSearch(const std::string& searchFor, Person* startOnNext)
{
	if (!startOnNext)
	{
		for (Person* ptr = persons; ptr != persons + maxSize; ptr++)
		{
			if (ptr->name == searchFor || ptr->address == searchFor)
			{
				return ptr;
			}
		}
	}
	else
	{
		for (Person* ptr = startOnNext + 1; ptr != persons + maxSize; ptr++)
		{
			if (ptr->name == searchFor || ptr->address == searchFor)
			{
				return ptr;
			}
		}
	}
	return nullptr;
}

PersonReg::~PersonReg()
{
	delete[] persons;
}


