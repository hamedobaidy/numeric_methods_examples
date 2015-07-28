/*
 * fixed_point_iteration_test.cpp
 *
 *  Created on: Jul 28, 2015
 *      Author: hamed
 */

#include <iostream>
#include <cmath>
#include <iomanip>

#include "root_finding.h"

double g(double x) {
	return 8 / 4.5 + sin(x);
}

int main(int argc, char **argv) {
	double root = 0.0;

	int status = fixed_point_iteration_root(g, 2.0, 0.0001, 20, root);

	if (status == 0) {
		std::cout << "Root found at x = " << std::setprecision(10) << root
				<< std::endl;
	} else {
		std::cout << "Something went wrong!\n";
	}

	return 0;
}

