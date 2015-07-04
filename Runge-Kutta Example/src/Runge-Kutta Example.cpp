//============================================================================
// Name        : Runge-Kutta.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Example 2 Section 21.1 Advanced Engineering Mathematics - Kreyszig
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
	return x + y;
}

int main() {
	double x = 0, y = 0, h = 0.2;

	cout << "n\tx\ty\tExact\tError\n";

	for (int n=0; n<6; n++) {
		double y_ex = exp(x)-x-1;
		cout << n << "\t" << x << "\t" << y << "\t" << y_ex << "\t" << y_ex - y<< endl;
		double k1 = h * f(x,y);
		double k2 = h * f(x+0.5*h, y +0.5*k1);
		double k3 = h * f(x+0.5*h, y +0.5*k2);
		double k4 = h * f(x+h, y + k3);
		x += h;
		y = y + (1/6.0)*(k1+2*k2+2*k3+k4);
	}

	return 0;
}
