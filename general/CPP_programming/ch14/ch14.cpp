#include <iostream>

class MyException : public exception
{
public:
	const char * what () const throw ()
	{
		return "C++ Exception";
	}
};

double division(int a, int b)
{
	if( b == 0 )
	{
		throw "Division by zero condition!";
	}
	return (a/b);
}

int main ()
{
	/* C++ - Exceptions */
	int x = 50;
	int y = 0;
	double z = 0;

	try
	{
		z = division(x, y);
		std::cout << z << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}

	try
	{
		throw MyException();
	}
	catch(MyException& e)
	{
		std::cout << "MyException caught" << std::endl;
		std::cout << e.what() << std::endl;
	}
	catch(std::exception& e)
	{
		//Other errors
	}

	return 0;
}

