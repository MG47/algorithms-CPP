/*
* Program to study function overloading and default arguments
*/

#include <iostream>

/* Default Arguments */
void print_args(int x, int y);

// 1. If a parameter is given a default argument,
// all subsequent parameters (to the right) must also be given default arguments.
// 2. It is better to use default args in function definition rather than declaraction
void print_args(int x = 1, int y = 5)
{
	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';
}

void print(int x, int y = 4)
{
	std::cout << "x: " << x << '\n';
	std::cout << "y: " << y << '\n';

	print_args(5);
}

void test_default_args()
{
	print(1);
	print(1, 10);
}

/* Function Overloading */

// Ambiguous - cannot differentiate based on return type
/*
int add(int a, int b, int c)
{
    std::cout << a + b + c << std::endl;
    return a + b + c;
}
*/

void add(int a, int b, int c)
{
	std::cout << a + b + c << std::endl;
}

void add(int a, int b)
{
	std::cout << a + b << std::endl;
}

void add(float a, float b)
{
    std::cout << a + b << std::endl;
}

void test_function_overload()
{
	add(1, 5);

	add(1, 5, 9);

	// ambiguous - literals are of type double
	// add(1.5, 2.1);

	add(1.5f, 2.1f);

	add(static_cast<float>(1.5), static_cast<float>(2.1));

}

int main()
{
	/* C++ - function overloading, default arguments */

	test_function_overload();

	test_default_args();

	return 0;
}


