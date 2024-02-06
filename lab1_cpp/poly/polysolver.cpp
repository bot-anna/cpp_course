#include <iostream>
#include "poly2.h"

int main(int argc, const char* argv[])
{
	std::cout << "Root-finding started..." << std::endl;
	std::cout << "Please give 3 numbers: " << std::endl;

    float a, b, c; 


    while (std::cin >> a >> b >> c) {
        Poly2 p(a, b, c);
		int num;
		float x1, x2;

		p.findRoots(num, x1, x2);

		switch (num) {
		case 0:
			std::cout << "Equation is missing real roots." << std::endl;
			break;
		case 1:
			std::cout << "Equation got 1 real root: " << x1 << std::endl;
			std::cout << "Eval: " << p.eval(x1) << std::endl;
			break;
		case 2:
			std::cout << "Roots are: " << x1 << " and " << x2 << std::endl;
			std::cout << "Eval: " << p.eval(x1) << " & " << p.eval(x2) << std::endl;
			break;
		}
    }

    
	return 0;
}
