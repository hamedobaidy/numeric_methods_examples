//============================================================================
// Name        : Runge-Kutta.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Example page 904 Section 21.1 Advanced Engineering Mathematics - Kreyszig
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
	return pow(y-x-1, 2) + 2;
}

int main() {
	double x = 0, y = 1.0, h = 0.1;

	cout << "n\tx\ty\tExact\tError\n";

	for (int n=0; n<5; n++) {
		double y_ex = tan(x)+x+1;
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
