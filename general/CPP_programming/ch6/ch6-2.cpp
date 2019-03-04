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

	test_class_ref();

	return 0;
}

