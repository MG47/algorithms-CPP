/*
* Program to study std::arrays
*/

#include <cstdio>
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

void print_arr(std::array<int, 10> *arr)
{
	for (std::array<int, 10>::iterator it = arr->begin();
		it != arr->end(); ++it) {
		printf("%d\n", *it);
	}
}

void print_arr(int *arr, unsigned int size)
{
	for (int i = 0; i < size; i++)
		printf("%d: %d\n", i, arr[i]);
}

void test_std_arrays()
{
	std::array<int, 10> arr;
	arr = {0};

	for (auto i : arr)
		printf("%d\n", arr[i]);

	for (int i = 0; i < arr.size(); i++) {
		arr[i] = i * i;
		printf("%d\n", arr[i]);
	}

	increment(arr);
	for (auto i : arr)
		printf("%d\n", arr[i]);

	// reverse sort, uses iterators
	std::sort(arr.rbegin(), arr.rend());
	for (auto i : arr)
		printf("%d\n", arr[i]);

	print_arr(arr.data(), arr.size());

	std::array<GraphicBuffer, 2> gb_arr;
	printf("size = %lu\n", gb_arr.size());

}

int main()
{
	/* C++ - std::arrays*/

	test_std_arrays();

	return 0;
}

