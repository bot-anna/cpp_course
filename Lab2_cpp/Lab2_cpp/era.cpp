#include "era.h"
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

Era::Era() {

}

void Era::find_primes() {
	const int n = 100;
	int nsqrt = (int) sqrt(n);

	int counter = 0;

	int arr[n];

	for (int c = 0; c < n - 2; c++) {
		arr[c] = c + 2;
	}

	for (int i = 2; i <= nsqrt; i++) {
		for (int j = i; j < n; j++) {
			if (arr[j] % i == 0) {
				arr[j] = 0;
			}
		}
	}

	for (int c = 0; c < n; c++) {
		if (arr[c] != 0) {
			cout << arr[c] << " ";
			counter++;
		}
	}
	cout << endl;

	cout << "Total prime numbers: " << counter << endl;
}