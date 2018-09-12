/*!
 * @file
 * @brief This file contains the test for the functions of Quadratic Equation
 */

#include "quadratic.h"


template<typename T1, typename T2>
class AssertionEqual
{
public:
		bool if_err_;
public:
		AssertionEqual(const T1& t1, const T2& t2, const char * description)
		{
			if_err_ = false;
			if (abs(t1 - t2) >= 0.000001) {
				std::cout << "----Assertion failed : roots count : " << t1 << " != "
															<< t2 << "(expected) : " << description << std::endl;
				if_err_ = true;
			}
		}
};

class SolveLineTest
{
		double x = 0;
public:
		SolveLineTest(double a, double b,
												int expd_root_count, const char * description)
		{
			AssertionEqual<int, int> assertionEqual(SolveLine(a, b, &x), expd_root_count, description);

			if (!assertionEqual.if_err_ && expd_root_count == 1)
			{
				if (abs(a*x + b) >= 0.000001) {
					std::cout << "----Assertion failed : " << x << " is not a root " << " : " << description << std:: endl;
				}
			}
		}
};

class SolveSquareTest
{
		double x1 = 0, x2 = 0;
public:

		SolveSquareTest(double a, double b, double c,
													int expd_root_count, const char * description)
		{
			AssertionEqual<int, int> assertionEqual(SolveSquare(a, b, c, &x1, &x2), expd_root_count, description);

			if (!assertionEqual.if_err_ && expd_root_count != 0 && expd_root_count != ss_inf_roots)
			{
				if (abs(a*x1*x1 + b*x1 + c) >= 0.000001)
				{
					std::cout << "----Assertion failed : " << x1 << " is not a root " << " : " << description << std::endl;
				}

				if (expd_root_count == 2) { // if we have two roots, let's check second root x2

					if (abs(a*x2*x2 + b*x2 + c) >= 0.000001)
					{
						std::cout << "----Assertion failed : " << x2 << " is not a root " << " : " << description << std::endl;
					}
				}
			}
		}
};

void SolveLineTester()
{
	SolveLineTest(0, 1, 0, "SolveLineTest1 : 1=0");

	SolveLineTest(0, 0, ss_inf_roots, "SolveLineTest2 : 0=0");

	SolveLineTest(2, 2, 1, "SolveLineTest3 : 2x+2=0");

	SolveLineTest(1, 0, 1, "SolveLineTest4 : x=0");

	SolveLineTest(1, 1.0000001, 1, "SolveLineTest5 : x+1.0000001=0");

	SolveLineTest(-5, 3, 1, "SolveLineTest6 : -5x+3=0");

	SolveLineTest(17, -13, 1, "SolveLineTest7 : 17x-13=0");


	std::cout<<"SolveLineTester completed"<<std::endl;
}

void SolveSquareTester()
{
	SolveSquareTest(0, 0, 0, ss_inf_roots, "SolveSquareTest1 : 0=0");

	SolveSquareTest(0, 0, 1, 0, "SolveSquareTest2 : 1=0");

	SolveSquareTest(0, 1, 1, 1, "SolveSquareTest3 : x+1=0");

	SolveSquareTest(1, 2, 1, 1, "SolveSquareTest4 : x^2 + 2x + 1 = 0");

	SolveSquareTest(2, 3, 5, 0, "SolveSquareTest5 : 2x^2 + 3x + 5 = 0");

	SolveSquareTest(1, 5, 6, 2, "SolveSquareTest6 : x^2 + 5x + 6 = 0");

	SolveSquareTest(17.24, 38.71, 14.56, 2,
									"SolveSquareTest6 : 17.24x^2 + 38.71x + 14.56 = 0");

	SolveSquareTest(-3, 1, 0, 2, "SolveSquareTest7 : -3x^2 + x = 0");

	std::cout<<"SolveSquareTester completed"<<std::endl;
}

void Tester(){
	SolveLineTester();
	SolveSquareTester();

	std::cout << "---FINISHED---" << std::endl;
}