/*
 * root_finding.cpp
 *
 *  Created on: Jul 25, 2015
 *      Author: hamed
 */

#include <cmath>

using namespace std;

#include "root_finding.h"

/**
 *
 * @param f function to be used for finding the root
 * @param a
 * @param b
 * @param tolerance
 * @param max_iter maximum iteration
 * @param root root to be find
 * @return status
 */
int bisection_root(double (*f)(double), double a, double b, double tolerance, int max_iter, double &root)
{
	double f_a = f(a);
	double f_b = f(b);

	if ( !((f_a * f_b ) < 0) )
		return -1;

	bool more_iteration = true;

	int i = 0;

	double x_ns = 0.0;

	do {
		double x_nsi = (a+b)/2;

		if ((f(a) * f(x_nsi)) <0) {
			b = x_nsi;
		} else {
			a = x_nsi;
		}

		if (fabs((x_nsi-x_ns)/x_ns) < tolerance || i >= max_iter) {
			more_iteration = false;
		}

		x_ns = x_nsi;

		i++;
	} while(more_iteration);

	root = x_ns;

	return 0;
}

/**
 *
 * @param f
 * @param a
 * @param b
 * @param tolerance
 * @param max_iter
 * @param root
 * @return status
 */
int regula_falsi_root(double (*f)(double), double a, double b, double tolerance, int max_iter, double & root)
{

	return 0;
}

/**
 *
 * @param f
 * @param x0
 * @param tolerance
 * @param max_iter
 * @param root
 * @return
 */
int newton_root(double (*f)(double), double x0, double tolerance, int max_iter, double &root)
{
	return 0;
}

/**
 *
 * @param f
 * @param x0
 * @param tolerance
 * @param max_iter
 * @param root
 * @return
 */
int secant_root(double (*f)(double), double x0, double tolerance, int max_iter, double& root)
{
	return 0;
}

/**
 *
 * @param f
 * @param x0
 * @param tolerance
 * @param max_iter
 * @param root
 * @return
 */
int fixed_point_iteration_root(double (*f)(double), double x0, double tolerance, int max_iter, double & root)
{
	return 0;
}
