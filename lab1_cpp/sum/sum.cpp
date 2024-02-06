#include <iostream>

int main() 
{
	int temp;
	int sum = 0;
	std::cout << "Welcome to this quantum calculator." << std::endl;
	std::cout << "Please give the integers you want to add to sum: " << std::endl;
	std::cout << "(Press ctrl + x when done)" << std::endl;
	while(std::cin >> temp) {
		sum += temp;
	}
	std::cout << "Sum is: " << sum << std::endl;

	return 0;
}