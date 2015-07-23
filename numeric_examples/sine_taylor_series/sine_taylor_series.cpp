/*
 * sine_taylor_series.cpp
 *
 *  Created on: Jul 21, 2015
 *      Author: hamed
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

double factorial(int);

int main(int argc, char **argv) {
	double eps = 0.000001;
	double x = 0;

	long long int MAX = numeric_limits<long long int>::max();

	bool another = true;
	char q = 'y';

	do {
		cout << "Enter x in degrees; ";
		cin >> x;

		cout << "x in degrees = " << x << endl;
		x = (fmod(x, 360) * M_PI) / 180;
		cout << "x in radians = " << x << endl;

		bool stop = true;
		double s_n = 0.0;
		int n = 0;
		double a_n = 0;

		do {
			if (x == 0) {
				n++;
				cout << "x == 0\n";
				break;
			}

			if (fmod(x, 2 * M_PI) <= eps || (2 * M_PI - x) <= eps) {
				n++;
				cout << "x = 2 * n * pi\n";
				break;
			}

			if (fmod(x, M_PI) <= eps || fabs(M_PI - x) <= eps) {
				n++;
				cout << "x = n * pi\n";
				cout << fmod(x, M_PI) << endl;
				break;
			}

			if (fmod(x, 3* M_PI / 2) <= eps || fabs(3 * M_PI / 2 - x) <= eps) {
				n++;
				s_n = -1;
				cout << "x = 3 * n * pi / 2\n";
				break;
			}

			double s = 0.0;
			if (n == 0) {
				a_n = x;
				s_n += a_n;
			} else {
				double fact = factorial(2 * n + 1);
				a_n = pow(-1, n) * ((pow(x, 2 * n + 1) / fact));
				s = s_n;
				s_n += a_n;

//				if (fact > MAX)
//					break;
			}

			double e = fabs((s_n - s) / s_n);

			if (e < eps || n > 50)
				stop = false;

			cout << "s_" << n << " = " << s_n << endl;

			n++;
		} while (stop);

		cout << "Converged at n = " << n - 1 << endl;
		cout << "s_n = sin(x) = " << s_n << endl;
		cout << "cmath, sin(x) = " << sin(x) << endl;

		cout << "Another number? ";
		cin >> q;

		if (q != 'y')
			another = false;

	} while (another);

	return 0;
}

double factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}
