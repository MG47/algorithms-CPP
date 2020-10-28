/*
* Program to study references
*/

#include <iostream>

class Person
{
	public:
		int age;
		std::string name;
};

void test_class_ref()
{
	Person per;
	Person &ref_per = per;

	per.age = 10;

	std::cout << "Age  = " << ref_per.age << std::endl;

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

void test_pass_by_reference()
{
	using namespace std;
	int arr[] = {1, 2, 3};
	incrementer(arr);

	cout << arr[0] << arr[1] << arr[2] << endl;

}

void test_const_ref(const int &ref_a, const int &ref_b)
{
	//ref_a++; //Illegal
	//ref_b++; //Illegal


	std::cout << "a = "  << ref_a << " b = "  << ref_b << std::endl;
}

void test_references()
{
	const int a = 5;
	int b = 7;

	//Illegal
	//a = 10;

	//Legal
	b = 12;

	const int &ref_a = a;
	const int &ref_b = b;

	test_const_ref(a, b);

}

int main()
{
	/* C++ - references  */

	test_references();

	test_pass_by_reference();

	test_return_by_reference();

	test_class_ref();

	return 0;
}

