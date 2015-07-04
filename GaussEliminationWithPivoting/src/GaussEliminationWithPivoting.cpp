//============================================================================
// Name        : GaussEliminationWithPivoting.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Gauss Elimination With Pivoting
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Enter matrix elements number : ";
	int n = 0;
	cin >> n;
	long double a[n][n + 1];

	// Get matrix elements from user
	for (int i = 0; i < n; i++) {
		cout << "Enter a" << i + 1 << " to a" << i + 1 << n << " and b" << i + 1
				<< " in a line and press Enter: ";
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		cin >> a[i][n];
	}

	// Show system of equations before Gauss elimination
	cout << "System of Equations Before Gauss Elimination\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << a[i][n] << endl;
	}

	// Pivoting
	for (int i = 0; i < n; i++) {
		if (a[i][i] == 0) {
			for (int j = i + 1; j < n; j++) {
				if (a[j][i] != 0) {
					long double temp[n + 1];
					for (int k = 0; k <= n; k++) {
						temp[k] = a[j][k];
						a[j][k] = a[i][k];
						a[i][k] = temp[k];
					}
					break;
				}
			}
		}
	}

	// Perform Gauss elimination
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			long double m = a[j][i] / a[i][i];
			for (int k = i; k < n; k++) {
				a[j][k] = a[j][k] - (m * a[i][k]);
			}
			a[j][n] = a[j][n] - (m * a[i][n]);
		}
	}

	// Show system of equations after Gauss elimination
	cout << "System of Equations After Gauss Elimination\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << a[i][n] << endl;
	}

	// Solving for x_i
	long double x[n];
	x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--) {
		long double sum = 0.0;
		for (int j = i + 1; j < n; j++) {
			sum += a[i][j] * x[j];
		}
		x[i] = (a[i][n] - sum) / a[i][i];
	}

	for (int i = 0; i < n; i++) {
		cout << "x" << i + 1 << " = " << x[i] << endl;
	}

	return 0;
}
