//============================================================================
// Name        : secant.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Secant root finding
//============================================================================

#include <iostream>
#include <cmath>
#include <cstdio>
#include <limits>
#include <iomanip>

using namespace std;

double fx(double x) {
	return 8 - 4.5 * (x - sin(x));
}

double secantRoot(double xA, double xB, double err, int imax) {
	double xs = 0.0;

	for (int i = 0; i < imax; i++) {
		double fXb = fx(xB);
		double xi = xB - fXb * (xA - xB) / (fx(xA) - fXb);
		if (abs((xi - xB) / xB) < err) {
			xs = xi;
			break;
		}
		xA = xB;
		xB = xi;

		if (i == imax - 1) {
			printf("Solution was not obtained in %i iterations", imax);
			xs = numeric_limits<double>::quiet_NaN();
		}
	}

	return xs;
}

int main() {
	double xSolution = secantRoot(2,3, 0.0001,10);
		if( !isnan(xSolution))
			cout << "xSolution = " << setprecision(16) << xSolution << endl;
	return 0;
}
