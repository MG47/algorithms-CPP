/*
* Program to study for-each
* (Range-based for loops)
*/

#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include <iostream>

void increment_vec(std::vector<double> &v)
{
	// by reference: elements are not copied to 'i'
	// elements can be modified
	for (auto &i : v)
		i++;
}

void print_vec(std::vector<double> &v)
{
	for (auto const &i : v)
		printf("%f\n", i);
}

int main()
{
	int arr[] = {0, 2, 1, 4, 4};
	for (auto i : arr)
		printf("%d\n", i);

	std::vector<double> vec;
	for (auto i = 0.2; i < 10; i++)
		vec.push_back(i);

	print_vec(vec);
	increment_vec(vec);
	print_vec(vec);

	std::string str[] = {"This", "is", "a", "string"};
	for (auto &s : str)
		std::cout << s << std::endl;

	std::list<double> mylist;
	mylist.push_back(1.0);
	mylist.push_back(2.0);
	mylist.push_back(3.0);
	mylist.push_back(4.0);

	for (auto &l : mylist)
		std::cout << l << std::endl;

	return 0;
}

