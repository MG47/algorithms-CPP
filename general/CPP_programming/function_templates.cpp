/*
* Program to study function templates
*/

#include <iostream>

// multiple template types
template <typename T, typename U>
T addAny(T a, U b)
{
	return a + b;
}

template <typename T>
T add(T a, T b)
{
	return a + b;
}

void test_function_templates()
{
	std::cout << add(1, 5) << std::endl;

	// compile error: no matching call for (double, int)
	//std::cout << add(1.2, 5) << std::endl;

	std::cout << add(1.2, 5.0) << std::endl;
	std::cout << static_cast<int>(add('a', 'c')) << std::endl;

	// function template instantiation
	std::cout << add<float>(1.0, 2.2) << std::endl;

	// Multiple types
	std::cout << addAny(1.2, 5) << std::endl;
}


int main()
{
	/* C++ - function templates */

	test_function_templates();

	return 0;
}


