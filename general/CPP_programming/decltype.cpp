/*
* Program to study decltype
*/

#include <cstdio>
#include <vector>

//TODO : templates

struct buf {
public:
	buf(bool linear)
	: mIsLinear(false),
	  mMap(nullptr)
	{
		mIsLinear = linear;
	};
	bool mIsLinear;
private:
	void *mMap;
};

void print_buflist(std::vector<struct buf> *bflist)
{
	for (std::vector<struct buf>::iterator it = bflist->begin();
		it != bflist->end(); ++it) {
		printf("buf : %s \n", (*it).mIsLinear ? "Linear" : "Non-Linear");
	}
}

void test_decltype()
{
	int a = 3;

	decltype(a) b = 10;

	struct buf bf_one(false);
	decltype(bf_one) bf_two(true);

	printf("a = %d\n", a);
	printf("b = %d\n", b);

	std::vector<decltype(bf_one)> buflist;
	buflist.push_back(bf_one);
	buflist.push_back(bf_two);

	print_buflist(&buflist);
}

int main()
{

	test_decltype();

	return 0;
}

