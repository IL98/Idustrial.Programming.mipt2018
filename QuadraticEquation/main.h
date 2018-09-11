#ifndef QUADRATICEQUATION_MAIN_H
#define QUADRATICEQUATION_MAIN_H

#include <iostream>
#include <cassert>
#include <cmath>

#define SS_INF_ROOTS -1
int SolveLine(double a, double b, double* x);


int SolveSquare(double a, double b, double c,
								double* x1, double* x2);



#endif //QUADRATICEQUATION_MAIN_H
