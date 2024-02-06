#include <vector>
#include <cstdlib>
#include <numeric>
#include <algorithm>
#include <iostream>
#include "Person.h"
#include "PersonReg.h"


std::vector<int> getRndIntVector(int size)
{
	std::vector<int> v(size);
	std::iota(v.begin(), v.end(), 50);

	std::random_shuffle(v.begin(), v.end());

	return v;
}

void print(int n)
{
	std::cout << n << " ";
}

bool Greater(int x, int y)
{
	return x > y;
}


void SortIntVector() 
{
	std::cout << "Sorting integers in a vector: " << std::endl;
	std::vector<int> v = getRndIntVector(10);
	std::for_each(v.begin(), v.end(), print);

	std::cout << std::endl;

	std::sort(v.begin(), v.end());
	std::for_each(v.begin(), v.end(), print);
	std::cout << "\n\n";
	
}


void SortIntArray()
{
	std::cout << "Sorting an integer array" << std::endl;
	int a[10];

	for (int i = 0; i < 10; i++)
	{
		a[i] = (rand() % 100);
	}

	std::for_each(a, a + 10, print);

	std::cout << std::endl;

	std::sort(a, a + 10);

	std::for_each(a, a + 10, print);
	std::cout << "\n\n";

}

void SortIntVectorRvrs()
{
	std::cout << "Sorting integer vector in decreasing order" << std::endl;
	std::vector<int> v = getRndIntVector(10);

	std::for_each(v.begin(), v.end(), print);

	std::cout << std::endl;

	std::sort(v.rbegin(), v.rend());

	std::for_each(v.begin(), v.end(), print);
	std::cout << "\n\n";

}

void SortIntArrayRvrs()
{
	std::cout << "Sorting an integer array in decreasing order" << std::endl;
	int a[10];

	for (int i = 0; i < 10; i++)
	{
		a[i] = (rand() % 100);
	}

	std::for_each(a, a + 10, print);

	std::cout << std::endl;

	std::sort(a, a + 10, Greater);

	std::for_each(a, a + 10, print);
	std::cout << "\n\n";
}

void addPersons(PersonReg& pr)
{
	pr.addToTest("sara", "apelgatan");
	pr.addToTest("sara", "bokgatan");
	pr.addToTest("sara", "citrongatan");
	pr.addToTest("bea", "doppelgatan");
	pr.addToTest("lisa", "ekgatan");
}

void SortPerson() 
{
	std::cout << "Sorting person on address:" << std::endl;
	PersonReg pr(5);
	addPersons(pr);
	std::random_shuffle(pr.begin(), pr.end());
	std::cout << "Pre-sort: " << std::endl;
	pr.Print();

	std::cout << std::endl;

	std::sort(pr.begin(), pr.end());
	std::cout << "Post-sort: " << std::endl;
	pr.Print();

	std::cout << "\n\n";


}

bool Even(int i) 
{
	return i % 2 == 0;
}

void RemoveEven()
{
	std::cout << "Remove even: " << std::endl;
	std::vector<int> v = getRndIntVector(10);
	std::for_each(v.begin(), v.end(), print);
	std::cout << std::endl;
	
	v.erase(std::remove_if(v.begin(), v.end(), Even), v.end());

	std::for_each(v.begin(), v.end(), print);
	std::cout << std::endl; 


}

int main() 
{
	SortIntVector();
	SortIntArray();
	SortIntVectorRvrs();
	SortIntArrayRvrs();
	SortPerson();
	RemoveEven();

	return 0;
}