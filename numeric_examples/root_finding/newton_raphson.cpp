/*
 * newton_raphson.cpp
 *
 *  Created on: Aug 5, 2015
 *      Author: hamed
 */

/**
 *
 * @param f
 * @param x0
 * @param tolerance
 * @param max_iter
 * @param root
 * @return status
 */
int newton_raphson_root(double (*f)(double), double (*fp)(double), double x0,
		double tolerance, int max_iter, double &root) {
	double x = x0;

	bool more_iteration = true;
	int i = 0;
	while (more_iteration) {
		double x_i = x - f(x) / fp(x);

		double tr_err = fabs((x_i - x) / x_i);
		if (tr_err < tolerance || i > max_iter)
			more_iteration = false;

		i++;
		x = x_i;
	}

	root = x;

	return 0;
}


