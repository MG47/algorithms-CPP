/*
* Program to study std::vectors
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <memory>


void print_2d_vector(std::vector<std::vector<int>> &matrix)
{
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

}

void test_2d_vectors()
{
	std::vector<std::vector<int>> matrix {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	print_2d_vector(matrix);
}

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

void do_square(std::vector<double> *v)
{
	if (!v)
		return;

	for (int i = 0; i < v->size(); i++)
		v->at(i) = v->at(i) * v->at(i);
}

void do_decrement(std::vector<double> &v)
{
	for (auto &i : v)
		i--;
}

void print_bufv(std::vector<struct buf *> &bufvp)
{
	for (std::vector<struct buf *>::iterator it = bufvp.begin(); it != bufvp.end(); ++it) {
		if ((*it)) {
			printf("buf: is linear ? %s\n", (*it)->mIsLinear ? "YES" : "NO");
		}
	}
	printf("buf: ==========\n");
}

void print_bufv(std::vector<struct buf> &bufv)
{
	if (bufv.empty())
		return;

	printf("bufv max_size = %lu\n", bufv.max_size());
	printf("bufv capacity = %lu\n", bufv.capacity());

	for (std::vector<struct buf>::iterator it = bufv.begin(); it != bufv.end(); ++it) {
		printf("buf: is linear ? %s\n", (*it).mIsLinear ? "YES" : "NO");
	}
	printf("buf: ==========\n");
}

void print_vec(std::shared_ptr<std::vector<int>> vptr)
{
	for (auto it = vptr->begin(); it != vptr->end(); ++it) {
		printf("%d\n", (*it));
	}
}

void test_vec_ptr()
{
	std::vector<int> v{1, 23, 17, 3, -1};
	std::shared_ptr<std::vector<int>> vptr(new std::vector<int>(v));
	print_vec(vptr);
}

void test_vectors()
{
	std::vector<double> vec;
	vec = {0.3, -0.3};

	std::vector<double>::iterator it;

	it = vec.begin();
	printf("at begin = %f\n", *it);

	std::advance(it, 1);
	printf("at end = %f\n", *it);

	for (it = vec.begin(); it != vec.end(); ++it) {
		printf("%f\n", *it);
	}

	for (it = vec.begin(); it != vec.end(); ++it) {
		int i = it - vec.begin();
		printf("%d: %f\n", i, vec[i]);
	}

	std::vector<struct buf> bufv;
	bufv.push_back(true);
	bufv.push_back(false);
	bufv.push_back(true);
	bufv.push_back(true);
	bufv.push_back(true);
	print_bufv(bufv);
	bufv.reserve(1 << 16);
	print_bufv(bufv);

	//TODO : iterator invalidation

	std::vector<struct buf*> bufvp;
	struct buf *b1 = new buf(true);
	struct buf *b2 = new buf(false);
	struct buf *b3;
	bufvp.push_back(b1);
	bufvp.push_back(b2);
	bufvp.push_back(b3);
	bufvp.pop_back();
	bufvp.emplace_back(new buf(true));


	print_bufv(bufvp);
	std::vector<struct buf*>::iterator bit =
		bufvp.erase(bufvp.begin() + 1, bufvp.end());
		printf("buffer: is linear ? %s\n", (*bit)->mIsLinear ? "YES" : "NO");

	print_bufv(bufvp);

	test_vec_ptr();
}

int main()
{
	/* C++ - vectors */

	test_vectors();

	test_2d_vectors();

	return 0;
}

