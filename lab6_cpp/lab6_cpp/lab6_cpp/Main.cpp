#include "Interpreter.h";
int main()
{
	Interpreter i(std::cout);
	i.execute("program.txt");
}