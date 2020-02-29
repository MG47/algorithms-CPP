/*
* Program to study lambdas
*/

#include <cstdio>

static inline int avg(int a, int b)
{
	return (a + b) / 2;
}

void test_lambda()
{
	int num_1 = 10, num_2 = 20;

	// without lambda
	printf("avg of %d and %d is = %d\n", num_1, num_2, avg(num_1, num_2));

	auto l_avg = [](int a, int b)
	{
		return (a + b ) / 2;
	};
	// with labmda
	printf("avg of %d and %d is = %d\n", num_1, num_2, l_avg(num_1, num_2));


	// labmda with captures
	auto c_avg = [num_1, num_2]()
	{
		return (num_1 + num_2 ) / 2;
	};
	printf("avg of %d and %d is = %d\n", num_1, num_2, c_avg());

}

int main()
{

	test_lambda();

        return 0;
}

