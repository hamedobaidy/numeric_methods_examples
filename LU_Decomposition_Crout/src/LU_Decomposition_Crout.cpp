//============================================================================
// Name        : LU_Decomposition_Crout.cpp
// Author      : Hamed Mohammadi
// Version     :
// Copyright   : GNU General Public License
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "Enter matrix elements count : ";
	int n = 0;
	cin >> n;
	double a[n][n];
	for (int i = 0; i < n; i++) {
		cout << "Enter a" << i +1 << i+1 << " to a" << i+1 << n << " in a line and press Enter: ";
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	cout << "A=\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

	double L[n][n];
	double U[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			L[i][j]=U[i][j]=0.0;
		}

	for (int i = 0; i < n; i++)
		L[i][0] = a[i][0];

	for (int i = 0; i < n; i++)
		U[i][i] = 1;

	for (int j = 1; j < n; j++)
		U[0][j] = a[0][j] / L[0][0];

	for(int i = 1; i < n; i++) {
		for(int j = 1; j < i+1; j++) {
			double sum = 0.0;
			for(int k = 0; k <= j; k++) {
				sum += L[i][k]*U[k][j];
			}
			L[i][j]=a[i][j] - sum;
		}

		for(int j = i+1; j < n; j++) {
			double sum = 0.0;
			for(int k = 0; k <= i; k++) {
				sum += L[i][k]*U[k][j];
			}
			U[i][j]=(a[i][j]-sum)/L[i][i];
		}
	}

	cout << "U=\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << U[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "L=\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << L[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}
