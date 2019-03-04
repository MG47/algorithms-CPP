#include <iostream>

void test_cast()
{
	char ch(97);
	int i(ch); // assign the value of ch to an integer
	int j;

	std::cout <<"Value of char ch: " << ch << std::endl; // print the char value

	std::cout <<"Value of char as int : " << i << std::endl; // print the integer value

	j = static_cast<int>(ch);
	std::cout <<"Value of char as int with static_cast:" << j <<std::endl;

	int x = 7;
	int y = 4;

	std::cout << "int / int = " << x / y << "\n";
	std::cout << "double / int = " << static_cast<double>(x) / y << "\n";
	std::cout << "int / double = " << x / static_cast<double>(y) << "\n";
	std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << "\n";
}

void print_types()
{
	bool decision;
	std::cout << "decision " << decision << "sizeof decision" << sizeof decision << std::endl;
	decision = true;
        std::cout << "decision " << decision << "sizeof decision" << sizeof decision << std::endl;

	// direct initialization
	int my_var(4);
	std::cout << "my_var  = " << my_var << std::endl;
	float my_another_var(3.5);
        std::cout << "my_another_var  = " << my_another_var << std::endl;

	//constexpr example
	const int a_const = 9;
        std::cout << "a_const  = " << a_const << std::endl;

	const int a_conexpr = 10;
        std::cout << "a_conexpr  = " << a_conexpr << std::endl;

        const int a_conexpr_arr[a_conexpr] = {0};
}

int main()
{
	/* C++ basic programming - continued */

	/* Print Hello World */
	print_types();

	test_cast();
}
