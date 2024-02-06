#include "String.h"
#include <iostream>
#include <stdexcept>
#include <cassert>

String::String()
{
	string = nullptr;
	cap = size_t(0);
	n = size_t(0);
	Invariant();
}

String::String(const String& rhs)
{	

	cap = rhs.cap; 
	string = new char[cap];
	n = rhs.n;

	for (size_t i = 0; i < n; i++)
	{
		string[i] = (rhs.string[i]);
	}
	Invariant();
}

String::String(const char* cstr)
{
	n = 0;

	while (*(cstr + n) != '\0')
	{
		n++;
	}

	string = new char[n];
	for (size_t i = 0; i < n; i++)
	{
		string[i] = cstr[i];
	}

	cap = n;
	Invariant();
}

String& String::operator=(const String& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	if (rhs.n > this->cap)
	{
		delete[] string;
		string = new char[rhs.cap];
	}
	
	n = rhs.n;
	cap = rhs.cap;

	for (size_t i = 0; i < n; i++)
	{
		string[i]= rhs.string[i];
	}
	Invariant();

	return *this;
}

char& String::operator[](size_t i)
{
	return string[i];
}

const char& String::operator[](size_t i) const
{
	return string[i];
}

size_t String::size() const
{
	return n;
}

size_t String::capacity() const
{
	return cap;
}

void String::push_back(char c)
{
	if (string == nullptr)
	{
		initialize_string();
	}
	 if (n == cap)
	 {
		 reserve(cap * 2);
	 }
	 string[n++] = c;
	 Invariant();
}

const char* String::data() const
{
	return string;
}

char& String::at(size_t i)
{
	if (i < 0 || i >= n)
	{
		throw std::out_of_range(" index out of range");
	}
	else
	{
		return (string[i]);
	}
}

const char& String::at(size_t i) const
{
	if (i < 0 || i > n)
	{
		throw std::out_of_range(" index out of range");
	}
	else
	{
		return (string[i]);
	}
}

void String::reserve(size_t newCap)
{
	if (newCap <= cap)
	{
		return;
	}
	char* copy = new char[newCap];

	for (size_t i = 0; i < n; i++)
	{
		copy[i] = string[i];
	}

	delete[] string;
	string = copy;
	cap = newCap;
	Invariant();

}

void String::shrink_to_fit()
{
	if (n < cap)
	{
		char* copy = new char[n]; 
		for (size_t i = 0; i < n; i++)
		{
			copy[i] = string[i];
		}

		delete[] string;
		string = copy;
		cap = n;
	}
	Invariant();
}
 

String& String::operator+=(const String& rhs)
{
	if (string == nullptr)
	{
		initialize_string();
	}
	if ((this->n + rhs.n) > cap)
	{
		reserve((this->n + rhs.n));
	}
	size_t j = 0;
	for (size_t i = n; i < (this->n + rhs.n); i++)
	{
		string[i] = rhs.string[j];
		j++;
	}
	n += j;
	Invariant();
	return *this;
}

String String::operator+(const String& rhs)
{
	return String(*this) += rhs;
}

String::~String()
{
	delete[] string;
}

void String::Invariant()
{
	assert(n <= cap);
	if (string == nullptr)
	{
		assert((n == 0) && (cap == 0));
	}
}

void String::initialize_string()
{
	string = new char[1];
	n = size_t(0);
	cap = size_t(1);
}

bool operator==(const String& lhs, const String& rhs)
{
	if (lhs.n == rhs.n)
	{
		for (size_t i = 0; i < lhs.n; i++)
		{
			if (lhs.string[i] != rhs.string[i])
			{
				return false;
			}
		}
		return true;

	}
	else
	{
		return false;
	}
}

bool operator!=(const String& lhs, const String& rhs)
{
	if (lhs.n == rhs.n)
	{
		for (size_t i = 0; i < lhs.n; i++)
		{
			if (lhs.string[i] != rhs.string[i])
			{
				return true;
			}
		}
		return false;

	}
	else
	{
		return true;
	}
}


std::ostream& operator<<(std::ostream& out, const String& rhs)
{
	for (size_t i = 0; i < rhs.n; i++)
	{
		out << rhs[i];
	}
	return out;
}