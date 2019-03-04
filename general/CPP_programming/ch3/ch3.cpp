#include <iostream>

void test_bit()
{
	char b = 0b00011000;
	int a = 0b0001101001101110;

	std::cout << "num b = " << static_cast<int>(b) << std::endl;
	std::cout << "num a = " << a << std::endl;
}

int main()
{
	/* C++ basic programming - binary literals */
	test_bit();
}

