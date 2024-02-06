#ifndef PERSONREG_H
#define PERSONREG_H
#include <string>
#include "Person.h"

class PersonReg {

public:
	Person* persons;
	int maxSize;
	int i;

	PersonReg(int maxSize);

	bool add(const Person* const p);

	bool addToTest(const std::string& name, const std::string& address);

	void removeEntry(Person* ptr);

	Person* searchName(const std::string& name) const;

	void Print() const;

	void empty();

	Person* begin();

	Person* end();

	Person* freeSearch(const std::string& searchFor, Person* startOnNext);


	~PersonReg();

};

#endif
