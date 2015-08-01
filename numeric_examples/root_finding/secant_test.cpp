/*
 * secant_test.cpp
 *
 *  Created on: Jul 28, 2015
 *      Author: hamed
 *      A program to test secant root finding function
 */

#include <iostream>
#include <cmath>
#include <iomanip>

#include "root_finding.h"

double fx(double x) {
	return 8 - 4.5 * (x - std::sin(x));
}

int main(int argc, char **argv) {
	double root = 0.0;

	int status = secant_root(fx, 2.0, 3.0, 0.0001, 20, root);

	if (status == 0) {
		std::cout << "Root found at x = " << std::setprecision(10) << root << std::endl;
	} else {
		std::cout << "Something went wrong!\n";
	}

	return 0;
}


