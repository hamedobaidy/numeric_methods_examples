/*
 * calculate_pi.cpp
 *
 *  Created on: Jul 24, 2015
 *      Author: hamed
 */

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv) {
	int n = 0;
	double sum = 0.0;
	cout << "Enter n: ";
	cin >> n;

	for (int i = 1; i <=n; i++) {
		sum += pow(-1, i-1)*(1.0/(2*i-1));
	}

	double pi = 4*sum;
	cout << "calculated pi = " << pi << endl;
	cout << "amath M_PI = " << M_PI << endl;
	double tr_err = fabs((M_PI-pi)/M_PI);
	cout << "True relative error = " << tr_err << endl;

	return 0;
}



