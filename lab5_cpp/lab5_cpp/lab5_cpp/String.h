#ifndef STRING_H
#define STRING_H
#endif
#include <vector>
#include <ostream>

class String {
public:
	char* string; //the string
	size_t n; //size
	size_t cap; //capacity

	String();
	String(const String& rhs);
	String(const char* cstr);
	String& operator=(const String& rhs);
	char& operator[](size_t i);
	const char& operator[](size_t i) const;
	size_t size() const;
	size_t capacity() const;
	void push_back(char c);
	friend bool operator==(const String& lhs, const String& rhs);
	friend bool operator!=(const String& lhs, const String& rhs);
	const char* data() const;
	friend std::ostream& operator<<(std::ostream& out, const String& rhs);
	char& at(size_t i);
	const char& at(size_t i) const;
	void reserve(size_t newCap);
	void shrink_to_fit();
	void print();
	void print() const;
	
	
	String& operator+=(const String& rhs);
	String operator+(const String& rhs);

	~String();

private:
	void Invariant();
	void initialize_string();
};