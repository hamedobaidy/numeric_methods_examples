//============================================================================
// Name        : Improved.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Example 1 Section 21.1 Advanced Engineering Mathematics - Kreyszig
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
	return x + y;
}

int main() {
	cout << "n\tx_n\ty_n\tExact\tErr Imp\tErr Euler" << endl;
	double x = 0, y = 0, h = 0.2, y_eu = 0;
	cout << 0.0 << "\t" << 0.0 << "\t" << 0.0 << "\t" << 0 << "\t" << 0 << "\t" << 0 << endl;

	for (int n = 1; n <=5; n++ ) {
		double x_np1 = x + h;
		double k1 = h * f(x, y);
		double k2 = h * f(x_np1, y + k1);
		y = y + 0.5 * (k1+k2);
		y_eu = y_eu + h* f(x, y_eu);
		x = x_np1;
		double y_ex = exp(x)-x-1;
		cout << n << "\t" << x << "\t" << y << "\t" << y_ex << "\t" << y_ex-y << "\t" << y_ex-y_eu << endl;
	}

	return 0;
}
