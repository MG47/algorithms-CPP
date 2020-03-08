/*
* Program to study vectors
*/

#include <vector>
#include <iostream>

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

void test_vectors()
{
	std::vector<double> vec;
	vec = {0.3, -0.3};

	for (auto el : vec)
		std::cout << el << std::endl;

	printf("element at %d: %f\n", 1, vec.at(1));

	do_square(&vec);
	for (auto el : vec)
		std::cout << el << std::endl;

	do_decrement(vec);
	for (auto el : vec)
		std::cout << el << std::endl;

	vec.resize(5);
	for (auto el : vec)
		std::cout << el << std::endl;

}

int main()
{
	/* C++ - vectors */

	test_vectors();

	return 0;
}

