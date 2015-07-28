/*
 * root_finding.h
 *
 *  Created on: Jul 25, 2015
 *      Author: hamed
 */

#ifndef ROOT_FINDING_H_
#define ROOT_FINDING_H_

int bisection_root(double (*f)(double), double, double, double, int, double &);

int regula_falsi_root(double (*f)(double), double, double, double, int, double &);

int newton_root(double (*f)(double), double (*fp)(double), double, double, int, double &);

int secant_root(double (*f)(double), double, double, double, int, double&);

int fixed_point_iteration_root(double (*f)(double), double, double, int, double &);

#endif /* ROOT_FINDING_H_ */
