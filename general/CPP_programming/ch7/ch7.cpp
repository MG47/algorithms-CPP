#include <iostream>

/* Default parameters*/
int sub(int a, int b = 10)
{
	return a - b;
}

void test_default_params()
{
        using namespace std;

        int a(2), b(3);
	int c(54), d(2);

        cout << " sub = " << sub(a) << endl;
        cout << " sub = " << sub(c, d) << endl;
}

/* Function overloading */
int sum(int a, int b)
{
	return a + b;
}

int sum(double a, double b)
{
	return (int)(a + b);
}

void test_func_overloading()
{
        using namespace std;

	int a(2), b(3);
	double c(2.5), d(4.1);

	cout << " sum = " << sum(a, b) << endl;
	cout << " sum = " << sum(c ,d) << endl;
}

/* Return by reference */
int& decrementer(int (&arr)[2])
{
	arr[0]--;
	return arr[0];
}

void test_return_by_reference()
{
	int arr[] = {4, 2};

	int val = decrementer(arr);
	std::cout << "val  = " << val << std::endl;

}

/* Pass by reference */
void incrementer(int (&arr)[3])
{
	arr[0]++;
	arr[1]++;
	arr[2]++;
}

void test_reference()
{
	using namespace std;
	int arr[] = {1, 2, 3};
	incrementer(arr);

	cout << arr[0] << arr[1] << arr[2] << endl;

}

int main()
{
	/* C++ - pass by reference, function overloading, default parameters  */

	test_reference();

	test_return_by_reference();

	test_func_overloading();

	test_default_params();

	return 0;
}

