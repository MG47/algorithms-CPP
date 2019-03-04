#include <iostream>
#include <string>

void test_typedef_alias()
{
	using myint_t = int;
	myint_t num = 15;
	std::cout << "num =" << num <<std::endl;
}

void test_strings()
{
	using namespace std;
	string str1("Hello");
	string str2 = "World";
	string str3;
	int len ;

	// copy str1 into str3
	str3 = str1;
	cout << "str3 : " << str3 << endl;

	// concatenates str1 and str2
	str3 = str1 + str2;
	cout << "str1 + str2 : " << str3 << endl;

	// total lenghth of str3 after concatenation
	len = str3.size();
	cout << "str3.size() :  " << len << endl;

	string str4 = "new string";
	cout << str4 << endl;
	cout << "str4 len:" << str4.size() << endl;
}

namespace no_cast {
	void test_bit()
	{
		char b = 'd';

		std::cout << "num b = " << b << std::endl;
	}
}

namespace no_cast {
	bool test_true()
	{
		return true;
	}
}


namespace stat_cast{
	void test_bit()
	{
		char b = 'd';

		std::cout << "num b with static_cast = " << static_cast<int>(b) << std::endl;
	}
}

void test_namespace()
{
	no_cast::test_bit();
	stat_cast::test_bit();

	std::cout << "True of False : " << (no_cast::test_true() ? "TRUE" : "FALSE") << std::endl;

	using namespace stat_cast;

	test_bit();
}

int main()
{
	/* C++ basic programming - Namespaces, typecast, strings */
	test_namespace();

	test_strings();

	test_typedef_alias();
}
