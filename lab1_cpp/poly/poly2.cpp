#include "poly2.h"
#include <cmath>
#include <iostream>

Poly2::Poly2(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

float Poly2::eval(float x)
{
	return (a * x * x) + (b * x) + c;

}

void Poly2::findRoots(int &num, float &x1, float &x2)
{
	
	float d = (b * b) - (4 * a * c);
	if (d < 0) 
	{
		num = 0;
	}
	else if (d == 0) 
	{
		x1 = ((b * -1) + sqrt(d)) / (2 * a);
		num = 1;
	}
	else
	{
		x1 = ((b * -1 + sqrt(d)) / (2 * a));
		x2 = ((b * -1 - sqrt(d)) / (2 * a));
		num = 2;
	}
	

}
/*
int main() {

	Poly2 p1(2.0f, -1.0f, -1.0f);

	std::cout << "y(5) = " << p1.eval(5.0f) << std::endl;

	int num;
	float x1, x2;

	p1.findRoots(num, x1, x2);

	switch (num) {
	case 0:
		std::cout << "Equation is missing real roots." << std::endl;
		break;
	case 1:
		std::cout << "Equation got 1 real root: " << x1 << std::endl;
		std::cout << "Eval: " << p1.eval(x1) << std::endl;
		break;
	case 2:
		std::cout << "Roots are: " << x1 << " and " << x2 << std::endl;
		std::cout << "Eval: " << p1.eval(x1) << " & " << p1.eval(x2) << std::endl;
		break;
	}

	
}*/