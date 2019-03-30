
#include <iostream>
#include <string.h>
#include "stack.h"

/* ==================================Test Stubs===================================== */

void test_int_stack()
{
	cstd::Stack<int> st(10);
	int *data = new int[20]();

	int push_data[] = {2, 4, -166, 0, 3, 99, -11, 22, 32,
		8, 22222, 12121, 999};

	st.print_stack();

	st.peek(data);
	std::cout << "data = " << *data << std::endl;

	st.push(push_data);
	st.print_stack();

	st.push(&push_data[1], 2);
	st.print_stack();

	st.push(&push_data[4]);
	st.print_stack();

	st.push(&push_data[5], 7);
	st.print_stack();

	st.pop(data, 2);
	std::cout << "data : " << *data << "," << *(data + 1) << std::endl;
	st.print_stack();

	st.peek(data);
	std::cout << "data = " << *data << std::endl;
	st.print_stack();

	st.push(&push_data[5], 1);
	st.print_stack();
}

void test_str_stack()
{
	cstd::Stack<std::string> st;

	std::string str[] = {"hello", "alpha", "delta", "charlie", "tango"};
	st.push(str);
	st.print_stack();

//	std::cout << "string at top : " << st.peek() << std::endl;

//	st.pop();
//	st.pop();
}

/* ============================================================== */

int main()
{
	std::cout << "==============Stack=============" << std::endl;

	test_int_stack();

	test_str_stack();

	return 0;
}


