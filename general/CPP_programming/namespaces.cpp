/*
* Program to study C++ namespace
*/

#include <cstdio>

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
	/* C++ - namespaces */

	test_namespace();

	return 0;
}

