//============================================================================
// Name        : Euler.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

double f(double x, double y) {
	return x + y;
}

int main() {
	double h = 0.2;
	double y = 0, x =0;

	cout << "n\tx_n\ty_n\ty(x_n)\t\tError" << endl;
	cout << 0 << "\t" << 0 << "\t" << 0 << "\t" << 0 << "\t\t" << 0 << endl;

	for(int n=1; n<=5; n++) {

		y = y + h* f(x, y);

		x = x + h;
		double y_ex = exp(x) - x -1;
		cout << n << "\t" << x << "\t" << y << "\t" << y_ex << "\t\t" << y_ex-y << endl;

	}

	return 0;
}


