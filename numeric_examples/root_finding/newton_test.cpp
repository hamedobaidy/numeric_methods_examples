/*
 * newton_test.cpp
 *
 *  Created on: Jul 28, 2015
 *      Author: hamed
 *
 *      A simple program to test newto method
 */

#include <iostream>
#include <cmath>
#include <iomanip>

#include "root_finding.h"

double fx(double x) {
	return 8 - 4.5 * (x - std::sin(x));
}

double fpx(double x) {
	return -4.5 + 4.5 * cos(x);
}

int main(int argc, char **argv) {
	double root = 0.0;

	int status = newton_root(fx, fpx, 2.0, 0.0001, 20, root);

	if (status == 0) {
		std::cout << "Root found at x = " << std::setprecision(10) << root
				<< std::endl;
	} else {
		std::cout << "Something went wrong!\n";
	}

	return 0;
}

