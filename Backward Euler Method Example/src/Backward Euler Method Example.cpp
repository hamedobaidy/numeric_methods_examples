//============================================================================
// Name        : Backward.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Example 4 Section 21.1 Advanced Engineering Mathematics - Kreyszig
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
	return -20 * y + 20 * pow(x, 2) + 2 * x;
}

int main() {
	double x = 0.0, y = 1.0, h = 0.05;
	cout << "Enter h: ";
	cin >> h;
	int steps = 1.0/h;

	for (int n = 0; n < steps+1; n++) {
		cout << x << "\t" << y << endl;
		y = (y + h * (20 * pow(x + h, 2) + 2 * (x + h))) / (1 + 20 * h);
		x += h;
	}
	return 0;
}
