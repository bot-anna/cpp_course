#include <iostream>

int main(int argc, const char* argv[])
{	
	std::cout << "Hello World!" << " Nice to see you, ";

	for(int i = 1; i < argc; i++) {
		std::cout << argv[i] << " ";
	}

	return 0;
}