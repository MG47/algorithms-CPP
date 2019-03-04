#include <algorithm>
#include <iostream>
#include <vector>

/* std::vectors */
void test_std_vectors()
{
	std::vector<double> my_arr;
	std::vector<int> my_int_arr = {1, 18, 2};

	//resize vector
	my_int_arr = {1, 18, 122, -2};

	std::cout << "size of my_arr " << my_arr.size() << std::endl;
        std::cout << "size of my_int_arr " << my_int_arr.size() << std::endl;

	my_int_arr.resize(2);
        std::cout << "size of my_int_arr " << my_int_arr.size() << std::endl;

	//both vectors are out of scope, deallocated here
}

/* std::arrays */
void print_my_array(std::array<int, 5> &my_arr)
{
	std::cout << "Printing my array:" << std::endl;
	for (auto i: my_arr)
		std::cout << i << std::endl;
}

void sort_my_array(std::array<int, 5> &my_arr)
{
	std::sort(my_arr.begin(), my_arr.end());
}

void test_std_arrays()
{
	std::array<int, 5> my_arr;
	std::array<int, 3> my_second_arr {1, 2, 3};

	my_arr = {11, 22, 33, 44, 55};

	std::cout << my_arr[1] << std::endl;

	my_arr.at(2) = 66;
	std::cout << my_arr.at(2) << std::endl;

	std::cout << "size of my_arr " << my_arr.size() << std::endl;

	sort_my_array(my_arr);

	print_my_array(my_arr);
}

void test_for_each()
{
	int arr[] = {1, 2, 3, 4, 5};

	std::cout << "arr" << std::endl;
	for (auto i: arr)
		std::cout << i << std::endl;
}

int main()
{
	/* C++ - for-each, std::arrays, std::vectors  */

	test_for_each();

	test_std_arrays();

	test_std_vectors();

	return 0;
}

