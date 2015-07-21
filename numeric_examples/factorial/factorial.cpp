/*
 * factorial.cpp
 *
 *  Created on: Jul 21, 2015
 *      Author: hamed
 */


#include <iostream>

using namespace std;

int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int main(int argc, char **argv) {
	int n = 0.0;
	cout << "Enter an integer:";
	cin >> n;

	int fact = factorial(n);

	cout << n << "! = " << fact << endl;

	return 0;
}


