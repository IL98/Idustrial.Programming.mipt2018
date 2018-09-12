/*!
 * @file
 * @brief This file is solver of Quadratic Equation
 */

#include "quadratic.h"

#define TESTING


/*!
 * Solves a linear equation ax + b = 0
 *
 * @param [in] a a-coffecient
 * @param [in] b b-coffecient
 * @param [out] x Pointer to the root
 *
 * @return Number of roots
 *
 * @note If you've got infinite number of roots,
 * 					this function returns SS_INF_ROOTS
 */
int SolveLine(double a, double b, double* x)
{

	assert(x != NULL);

	assert(std::isfinite(a));
	assert(std::isfinite(b));

	if (a == 0)
	{
		return (b == 0) ? ss_inf_roots : 0;
	}
	else
	{
		*x = -b/a;
		return 1;
	}

}

/*!
 * Solves a quadratic equation ax^2 + bx + c = 0
 *
 * @param [in] a a-coffecient
 * @param [in] b b-coffecient
 * @param [in] c c-coffecient
 * @param [out] x1 Pointer to the first root
 * @param [out] x2 Pointer to the second root
 *
 * @return Number of roots
 *
 */
int SolveSquare(double a, double b, double c,
															double* x1, double* x2)
{

	assert(x1 != NULL);
	assert(x2 != NULL);
	assert(x1 != x2);

	assert(std::isfinite(a));
	assert(std::isfinite(b));
	assert(std::isfinite(c));

	if (a == 0)
	{
		return SolveLine(b, c, x1);
	}
	else /* if (a != 0) */
	{
		double d = b*b - 4*a*c;
		if (abs(d) < 0.0000001)
		{
			*x1 = -b / (2*a);
			return 1;
		}
		else /*if (d != 0)*/
		{
			if (d < 0)
			{
				return 0;
			}
			else
			{
				double sqrt_d = sqrt (d);

				*x1 = (-b - sqrt_d) / (2*a);
				*x2 = (-b + sqrt_d) / (2*a);

				return 2;
			}

		}
	}
}


int main()
{
#ifdef TESTING
	Tester();

	return 0;
#endif

	std::cout << "# Hello, it's Quadratic Equation solver\n" <<
							 "# September, 2018\n\n";
	std::cout << "Enter coefficients - a, b, c:"<<std::endl;


	double a = 0, b = 0, c = 0;
	std::cin >> a >> b >> c;

	double x1 = 0, x2 = 0;

	int quantityRoots = SolveSquare(a, b, c, &x1, &x2);

	switch (quantityRoots)
	{
		case 0: std::cout << "No roots"<< std::endl;
						break;

		case 1: std::cout << "x = "<< x1 << std::endl;
						break;

		case 2: std::cout << "x1 = "<< x1 <<
											   ", x2 = "<< x2 << std::endl;
						break;

		case ss_inf_roots: std::cout << "any number"<< std::endl;
						break;

		default: std::cout << "main(): Error: quantityRoots = "
											 <<quantityRoots<<std::endl;
						return 1;
	}

	return 0;
}