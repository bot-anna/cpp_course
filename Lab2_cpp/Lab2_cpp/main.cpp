#include <iostream>
#include <cmath>
#include "era.h"
#include "stringmani.h"
using std::cin;
using std::cout;
using std::endl;


int main()
{
	
	Era era;
	era.find_primes();
	
	cout << endl;

	StringMani sm;
	std::string iostring = "Hej pej dej";
	std::string before("ej");
	std::string after("ijeje");
	cout << "Iostring: " << iostring << "\nBefore-string: " << before << "\nAfter-string: " << after << endl;
	cout << "After manipulation: ";
	sm.substitute_str_std(iostring, before, after);
	cout << iostring << endl;

	cout << endl;
	
	const char* input = "Nationalencyklopedin";
	const char before_char = 'n';
	const char* after_char = "MANNEN";
	cout << "Input: " << input << "\nBefore-string: " << before_char << "\nAfter-string: " << after_char << endl;
	cout << "After manipulation: ";

	char* output = sm.substitute_str_c(input, before_char, after_char);


	cout << output << endl;

	delete[] output;

	return 0;
}