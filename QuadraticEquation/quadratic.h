#ifndef QUADRATICEQUATION_MAIN_H
#define QUADRATICEQUATION_MAIN_H

#include <iostream>
#include <cassert>
#include <cmath>

const int ss_inf_roots  = -1;


int SolveLine(double a, double b, double* x);


int SolveSquare(double a, double b, double c,
								double* x1, double* x2);

void SolveLineTester();

void SolveSquareTester();

void Tester();
#endif //QUADRATICEQUATION_MAIN_H
