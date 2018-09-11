/*!
 * @file
 * @brief This file contains the test for the functions of Quadratic Equation
 */

#include "main.h"


void SolveLineTest()
{
	double x = 0;
	assert(SolveLine(0, 1, &x) == 0);
	assert(SolveLine(0, 0, &x) == SS_INF_ROOTS);

	assert(SolveLine(2, 2, &x) == 1);
	assert(x == -1);

	assert(SolveLine(1, 0, &x) == 1);
	assert(x == 0);

	assert(SolveLine(1, 1.0000001, &x) == 1);
	assert(x == -1.0000001);

	assert(SolveLine(-5, 3, &x) == 1);
	assert(x == 0.6);

	assert(SolveLine(17, -13, &x) == 1);
	assert(abs(x - 0.76470588) < 0.00000001);


	std::cout<<"SolveLineTest is OK"<<std::endl;
}

void SolveSquareTest()
{
	double x1 = 0, x2 = 0;

	assert(SolveSquare(0, 0, 0, &x1, &x2) == SS_INF_ROOTS);

	assert(SolveSquare(0, 0, 1, &x1, &x2) == 0);

	assert(SolveSquare(0, 1, 1, &x1, &x2) == 1);
	assert(x1 == -1);

	assert(SolveSquare(1, 2, 1, &x1, &x2) == 1);
	assert(x1 == -1 && x2 ==-1);

	assert(SolveSquare(2, 3, 5, &x1, &x2) == 0);

	assert(SolveSquare(1, 5, 6, &x1, &x2) == 2);
	assert(x1 == -3 && x2 == -2);


	assert(SolveSquare(17.24, 38.71, 14.56, &x1, &x2) == 2);
	assert(abs(17.24*x1*x1 + 38.71*x1 + 14.56) < 0.000001);
	assert(abs(17.24*x2*x2 + 38.71*x2 + 14.56) < 0.000001);

	assert(SolveSquare(-3, 1, 0, &x1, &x2) == 2);
	assert(abs(x1 - 0.33333) < 0.00001);
	assert(x2 == 0);

	std::cout<<"SolveSquareTest is OK"<<std::endl;
}
