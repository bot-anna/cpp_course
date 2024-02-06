#include "PersonWithPhone.h"

PersonWithPhone::PersonWithPhone(std::string name, std::string address, std::string number) : Person(name, address), number(number)
{

}

void PersonWithPhone::Print()
{
	std::cout << "Name: " << name << "\nAddress: " << address << "\nPhone number: " << number << std::endl;
}

PersonWithPhone::~PersonWithPhone()
{
	std::cout << "Destroying " << name << " with address " << address << " and phone number " << number << " !!" << std::endl;
}
