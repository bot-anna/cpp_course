#ifndef STRINGMANI_H
#define STRINGMANI_H
#include <iostream>

class StringMani {
public:
	void substitute_str_std(std::string& iostring, const std::string& before, const std::string& after);

	char* substitute_str_c(const char* input, const char before, const char* after);
};

#endif