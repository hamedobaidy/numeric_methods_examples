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

unsigned long long factorial(unsigned long long);

int main(int argc, char **argv) {
	double eps = 0.000001;
	double x = 0;

	bool another = true;
	char q = 'y';

	do {
		cout << "Enter x in degrees; ";
		cin >> x;

		x = (fmod(x, 360) * M_PI) / 180;
		cout << "x in radian = " << x << endl;

		bool stop = true;
		double s_n = 0.0;
		int n = 0;
		double a_n = 0;

		do {
			if (x == 0) {
				n++;
				break;
			}

			if (fmod(x, 2 * M_PI) <= eps || (2 * M_PI - x) <= eps) {
				n++;
				break;
			}

			if (fmod(x, M_PI) <= eps || (M_PI - x) <= eps) {
				n++;
				break;
			}

//			if (fmod(x, 3 * M_PI / 2) <= eps || (3 * M_PI / 2 - x) <= eps) {
//				n++;
//				s_n = -1;
//				break;
//			}
//
//			if (fmod(x, M_PI / 2) <= eps || (M_PI / 2 - x) <= eps) {
//				n++;
//				s_n = 1;
//				break;
//			}


			double s = 0.0;
			if (n == 0) {
				a_n = x;
				s_n += a_n;
			} else {
				double fact = factorial(2 * n + 1);
				a_n = pow(-1, n) * ((pow(x, 2 * n + 1) / fact));
				s = s_n;
				s_n += a_n;
			}

			double e = fabs((s_n - s) / s_n);

			if (e < eps || n > 20)
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

unsigned long long factorial(unsigned long long n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}
