/*
* Program to study exceptions
*/

#include <exception>
#include <cstdio>

class MyException : public std::exception
{
public:
	const char * what () const throw()
	{
		return "C++ Exception";
	}
};

double division(int a, int b)
{
	if (b == 0) {
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
		printf("z = %f\n", z);
	}
	catch (const char* msg)
	{
		printf("msg = %s\n", msg);
	}

	try
	{
		throw MyException();
	}
	catch(MyException& e)
	{
		printf("MyException caught\n");
		printf("%s\n", e.what());
	}
	catch(std::exception& e)
	{
		//Other errors
	}

	return 0;
}

