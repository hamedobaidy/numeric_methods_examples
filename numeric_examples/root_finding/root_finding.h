/*
 * root_finding.h
 *
 *  Created on: Jul 25, 2015
 *      Author: hamed
 */

#ifndef ROOT_FINDING_H_
#define ROOT_FINDING_H_

int bisection_root(double (*f)(double), double, double, double, int, double &);

double regula_falsi_root(double (*f)(double), double, double);

double newton_root(double (*f)(double), double);

double secant_root(double (*f)(double), double);

double fixed_point_iteration_root(double (*f)(double), double);

#endif /* ROOT_FINDING_H_ */
