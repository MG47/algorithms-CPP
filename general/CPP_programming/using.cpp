/*
* Program to study C++ 'using'
*/

#include <cstdio>
#include <stdint.h>
#include <vector>

namespace intlengths {

struct dimensions {
	uint32_t length;
	uint32_t width;
	uint32_t height;
};

} // namespace intlengths

namespace floatlengths {

struct dimensions {
	float length;
	float width;
	float height;
};

} // namespace floatlengths

int printer(std::string &s)
{
    std::cout << s << std::endl;
}

void test_typedef_alias()
{
	using myint_t = int;
	myint_t num = 15;
	printf("num = %d\n", num);

	/* namespace */
	using namespace intlengths;
	struct dimensions ds = {1, 2, 3};

	printf("ds lxwxh = %f x %f x %f\n", static_cast<float>(ds.width),
		static_cast<float>(ds.width), static_cast<float>(ds.height));

	floatlengths::dimensions dsf = {1.2, 1.4, 1.5};
	printf("ds lxwxh = %f x %f x %f\n", dsf.length, dsf.width, dsf.height);


	/* Simplify complex names */
	std::vector<std::pair<std::string, int>> pairlist;

	using prlist = std::vector<std::pair<std::string, int>>
	prlist pairlist2;


	/* Function pointer typdef vs using */
	std::string s("Hello World");
	printer(s);

	typedef int(*funcptr_t)(std::string &);

	funcptr_t funcp = printer;
	funcp(s);

	using funcptr2_t = int(*)(std::string &);

	funcptr2_t funcp2 = printer;
	funcp2(s);
}

int main()
{
	/* C++ - using */

	test_typedef_alias();

	return 0;
}

