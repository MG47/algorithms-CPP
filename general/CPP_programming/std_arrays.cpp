/*
* Program to study std::arrays
*/

#include <iostream>
#include <array>
#include <algorithm>

struct GraphicBuffer {
	size_t size;
	void *mem;
};

void increment(std::array<int, 10> &arr)
{
	for (auto &i : arr)
		i++;
}

void test_std_arrays()
{
	std::array<int, 10> arr;
	arr = {0};

	for (auto i : arr)
		std::cout << i << std::endl;

	for (int i = 0; i < arr.size(); i++) {
		arr[i] = i * i;
		printf("%d\n", arr[i]);
	}

	increment(arr);
	for (auto i : arr)
		std::cout << i << std::endl;

	// reverse sort, uses iterators
	std::sort(arr.rbegin(), arr.rend());
	for (auto i : arr)
		std::cout << i << std::endl;

	std::array<GraphicBuffer, 2> gb_arr;
	printf("size = %lu\n", gb_arr.size());
}

int main()
{
	/* C++ - std::arrays*/

	test_std_arrays();

	return 0;
}

