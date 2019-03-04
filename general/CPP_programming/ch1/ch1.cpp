#include <iostream>
#include "ch1.h"

int read_input_and_add_var(const int var)
{
	int num;
	std::cin >> num;
	return num + var;
}

void print_statements()
{
	//statements
	int x = 10;
	std::cout << "x = " << x << std::endl;

	//expressions
	int y = 4 + x;
	std::cout << "y = " << y << " & x = " << x << std::endl;
}

void print_hello()
{
        std::cout << "Hello World!" << std::endl;

}

int main()
{
	/* C++ basic programming */

	/* Print Hello World */
	print_hello();

	/* Print Statement */
	print_statements();

	/* inputs */
	int num = read_input_and_add_var(6);
        std::cout << "num = " << num << std::endl;

	int sum = add(4, 6);
	std::cout<< "sum = " << sum << std::endl;
}

