#include "stringmani.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;



void StringMani::substitute_str_std(std::string& iostring, const std::string& before, const std::string& after)
{
	int i = 0;
	int j = 0;
	int count = 0;
	string::size_type b_size = before.size();
	string::size_type a_size = after.size();
	

	for (i = 0; i < iostring.size(); i++) {
		if(iostring[i] == before[j])
		{
			for (j = 0; j < b_size; j++) 
			{
				if (iostring[i + j] == before[j])
				{
					count++;
				}
			}
			if (count == b_size)
			{
				iostring.replace(i, b_size, after);

			}
			i += a_size - 1;
			count = 0;
			j = 0;
		}
	 }
	/*
	I learned about the find-method after writing this code, so this could also be done with a while loop
	using the find method, but I would guess that the find method looks something similar to this, so I chose 
	to keep this method as it is and live with the fact that I wrote more code than I had to do.
	*/
}

char* StringMani::substitute_str_c(const char* input, const char before, const char* after)
{
	auto input_len = strlen(input);
	int num_befores = 0;
	auto after_len = strlen(after);
	int j = 0; 

	for (int i = 0; i < input_len; i++) {
		if (input[i] == before)
		{
			num_befores++;
		}
	}

	int new_len = input_len + (after_len * num_befores) - num_befores + 1; //+1 for the nullchar

	char* output = new char[new_len]; 

	for (int i = 0; i < input_len; i++) 
	{
		if (input[i] == before) 
		{
			for (int n = 0; n < after_len; n++)
			{
				output[j] = after[n];
				j++;
			}
		}
		else 
		{
			output[j] = input[i];
			j++;
		}
	}

	output[new_len - 1] = '\0';
	
	return output;
}
 