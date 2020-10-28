/*
* Program to study STL - Part I
*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void test_algorithms()
{
	std::list<int> my_list;

	/* Generate random numbers between 1-20 */
	srand(time(0));
	for (int i = 0; i < 20; i++)
		my_list.push_back(rand() % 20);
	std::cout << std::endl;

	std::list<int>::const_iterator iter;

	iter = my_list.begin();
	while (iter != my_list.end()) {
		std::cout << *iter << ' ';
		iter++;
	}
	std::cout << std::endl;

	/* Sort list */
	my_list.sort();
	iter = my_list.begin();
	while (iter != my_list.end()) {
		std::cout << *iter << ' ';
		iter++;
	}
	std::cout << std::endl;

	iter = min_element(my_list.begin(), my_list.end());
	std::cout << "Min element = " << *iter << std::endl;

	iter = max_element(my_list.begin(), my_list.end());
	std::cout << "Max element = " << *iter << std::endl;
}

void test_iterators()
{
	std::vector<int> my_vec;

	for (int i = 0; i < 10; i++)
		my_vec.push_back(i);

	std::vector<int>::const_iterator iter;
	iter = my_vec.begin();
	std::cout << "Beginning element = " << *iter << std::endl;

	int last = my_vec.back();
	std::cout << "Ending element = " << last << std::endl;

	while (iter != my_vec.end()) {
		std::cout << *iter << ' ' ;
		iter++;
	}
}

void test_deque()
{
	std::deque<float> my_deq;
	for (float i = 0; i < 10; i++) {
		my_deq.push_back(i + 2.5);
		my_deq.push_front(i - 2.5);
	}

	for (int i = 0; i < my_deq.size(); i++)
		std::cout << my_deq[i] << std::endl;
}

void test_vector()
{
	std::vector<int> my_vec;

	for (int i = 0; i < 10; i++)
		my_vec.push_back(i + 10);

	for (int i = 0; i < my_vec.size(); i++)
	        std::cout << my_vec[i] << std::endl;
}

int main ()
{
	/* C++ - STL */

	test_vector();

	test_deque();

	test_iterators();

	test_algorithms();

	return 0;
}

