//============================================================================
// Name        : bisection.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Root-finding using bisection method example
//============================================================================

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double f(double x) {
	return 8-4.5*(x-sin(x));
}

int main() {
	double a = 2, b = 3, tol = 0.001;
	int imax = 20;

	cout << "iteration\ta\tb\t(xNS) Solution\tf(xNS)\tTolerence\n";
	for (int i = 0; i < imax; i++ ) {
		double xNS =(a+b)/2.0;
		double toli = (b-a)/2.0;
		double fxNS = f(xNS);
		printf("%3i %11.6f %11.6f %11.6f %11.6f %11.6f\n", i+1, a, b, xNS, fxNS, toli);
		if(fxNS == 0) {
			printf("An exact solution x=%11.6f was found", xNS );
			break;
		}
		if(toli < tol ) {
			break;
		}

		if( i == imax -1  ) {
			printf("Solution was not obtained in %i iterations", imax );
			break;
		}

		if(f(a)*fxNS <0)
			b = xNS;
		else
			a = xNS;

	}

	return 0;
}
