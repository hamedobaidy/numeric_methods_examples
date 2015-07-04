//============================================================================
// Name        : newton.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Newto method example
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

double fpx(double x) {
	return -4.5 +4.5 * cos(x);
}

double newtonRoot( double xEst, double err, int imax) {
	double xs = 0;

	for(int i = 0; i < imax; i++) {
		double xi = xEst - fx(xEst)/fpx(xEst);
		if(abs((xi - xEst )/xEst) < err) {
			xs = xi;
			break;
		}
		xEst = xi;

		if(i == imax -1) {
			printf("Solution was not obtained in %i iterations", imax );
			xs = numeric_limits<double>::quiet_NaN();
		}
	}

	return xs;
}

int main() {
	double xSolution = newtonRoot(2,0.0001,10);
	if( !isnan(xSolution))
		cout << "xSolution = " << setprecision(16) << xSolution << endl;
	return 0;
}
