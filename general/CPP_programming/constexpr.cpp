/*
* Program to study constexpr
*/

#include <cstdio>
#include <array>

const inline float get_value_of_pi()
{
	return 3.14;
}

constexpr inline float get_constexpr_value_of_pi()
{
	return 3.14;
}

const inline unsigned int get_len_of_array()
{
	return 5;
}

constexpr inline unsigned int get_constexpr_len_of_array()
{
	return 5;
}

int main()
{

	/* Example 1 */
	double PI = 3.14;

	const double PI_VALUE = 3.14;

	// value can be obtained at runtime
	const double PI_val = get_value_of_pi();

	// Cannot do, constexpr needs to be compile-time constant
	// constexpr double val_of_PI = get_value_of_pi();

	constexpr double constexpr_val_of_PI = get_constexpr_value_of_pi();


	printf("value of PI %f\n", PI);
	printf("value of PI_VALUE %f\n", PI_VALUE);
	printf("value of PI_val %f\n", PI_val);
	printf("value of val_of_PI %f\n", constexpr_val_of_PI);


	/* Example 2 */
	const int len_of_array = 5;

	// valid
	std::array<int, len_of_array> arr;
	printf("size of array arr %u\n", arr.size());

	// not valid
	// std::array<int, get_len_of_array()> arr32;


	std::array<int, get_constexpr_len_of_array()> arr2;
	printf("size of array arr2 %u\n", arr2.size());

	return 0;
}

