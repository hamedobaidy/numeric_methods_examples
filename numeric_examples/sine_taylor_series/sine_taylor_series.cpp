/*
 * sine_taylor_series.cpp
 *
 *  Created on: Jul 21, 2015
 *      Author: hamed
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int factorial(int);

int main(int argc, char **argv) {
	double eps = 0.000001;
	double x = 0;
	cout << "Enter x in degrees; ";
	cin >> x;

	x = (fmod(x, 360) * M_PI) / 180;
	cout << "x in radian = " << x << endl;

	bool stop = true;
	double s_n = 0.0;
	int n = 0;
	double a_n = 0;

	do {
		double s = 0.0;
		if (n == 0) {
			a_n = x;
			s_n += a_n;
		} else {
			a_n = (pow(-1, n) / (factorial(2 * n + 1))) * pow(x, 2 * n + 1);

			s = s_n;
			s_n += a_n;
		}

		double e = fabs((s_n - s) / s_n);

		if (e < eps || n > 100)
			stop = false;

		cout << "s_" << n << " = " << s_n << endl;

		n++;
	} while (stop);

	cout << "Converged at n = " << n << endl;
	cout << "s_n = sin(x) = " << s_n << endl;
	cout << "cmath, sin(x) = " << sin(x) << endl;

	return 0;
}

int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}
