/*
* queue.cpp - Implementation of circular queue data structure
*/

#include <iostream>
#include <string.h>
#include "queue.h"
#include "box.h"

/* ==================================Test Stubs===================================== */

void test_int_queue()
{
	std::cout << "\n\n";
	std::cout << "Test with Integers" << std::endl;

	int num = 4;
	int arr[] = {2, 1, -1, 12223, 212, 66, -55, 212};
	int *data = new int[20];

	cstd::Queue<int> q(4, 1);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;

	q.enqueue(&num);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;

	q.enqueue(arr);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;

	q.dequeue(data, 4);
	q.dequeue(data, 2);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;

	q.enqueue(arr, 4);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;


	q.dequeue(data, 4);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;
}

void test_string_queue()
{
	std::string str_arr[] = {"Hello", "world", "motto", "alpha", "charlie", "tango"};
	std::string my_string = "delta";
	std::string *data = new std::string[4];

	cstd::Queue<std::string> q(3, 1);

	q.enqueue(str_arr);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;

	q.dequeue(data);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;

	q.enqueue(str_arr, 2);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;

	q.enqueue(&my_string);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;

	q.enqueue(&str_arr[1]);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i] << std::endl;
}

void test_box()
{
	std::cout << "\n\n";
	std::cout << "Test with Box" << std::endl;
	Box b1, b2, b3;
	Box box_arr[] = {b1, b2, b2};
	Box data[3];

	cstd::Queue<Box> q(4);
	q.enqueue(box_arr, 2);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i].get_id() << std::endl;

	q.dequeue(data, 1);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i].get_id() << std::endl;

	q.enqueue(box_arr, 2);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i].get_id() << std::endl;

	q.enqueue(box_arr, 2);
	for (int i = 0; i < q.get_maxsize(); i++)
		std::cout << i << ":" << q[i].get_id() << std::endl;

}

/* ============================================================== */

int main()
{
	std::cout << "==============Queue=============" << std::endl;

	test_int_queue();

	test_string_queue();

	test_box();

	return 0;
}


