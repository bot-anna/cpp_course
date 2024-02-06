/*
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main()
{
	std::vector<char> v(1);

	cout << v.size() << endl; //prints 1
	cout << v.capacity() << endl; //prints 1

	v.push_back('k');
	cout << v.size() << endl; //prints 2
	cout << v.capacity() << endl; //prints 2
	v.push_back('a');
	cout << v.size() << endl; //prints 3
	cout << v.capacity() << endl; //prints 3
	v.push_back('l');
	cout << v.size() << endl; //prints 4
	cout << v.capacity() << endl; //prints 4
	v.push_back('l');
	cout << v.size() << endl; //prints 4
	cout << v.capacity() << endl; //prints 4
	v.push_back('e');
	cout << v.size() << endl; //prints 5
	cout << v.capacity() << endl; //prints 6

	cout << v.size() << endl; //prints 6
	cout << v.capacity() << endl; //prints 6

	cout << v.at(1) << endl; //prints k


	v.shrink_to_fit();

	cout << v.size() << endl; //prints 6
	cout << v.capacity() << endl; //prints 6

	v.reserve(20);

	cout << v.capacity() << endl; //prints 20

	v.shrink_to_fit();

	cout << v.size() << endl; //prints 6
	cout << v.capacity() << endl; //prints 6





	
	return 0;

}*/