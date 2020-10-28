/*
* Program to study C++ 'using'
*/

#include <cstdio>

void test_typedef_alias()
{
	using myint_t = int;
	myint_t num = 15;
	std::cout << "num =" << num <<std::endl;
}

int main()
{
	/* C++ - using */

	test_typedef_alias();

	return 0;
}

