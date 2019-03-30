
#include <iostream>
#include "list.h"

 /* ==================================Test Stubs===================================== */

void test_int_list()
{
	cstd::List<int> list;
	list.insert(2);
	list.insert(1);
	list.insert(-22);
	list.insert(-44);
	list.print_list();

	std:: cout << "head : " << list.head() << std::endl;

	list.remove(2);
	list.remove(5);
	list.print_list();

	std:: cout << "tail : " << list.tail() << std::endl;

	list.remove(-22);
	list.remove(-44);
	list.insert(-12);
	list.remove(1);
	list.print_list();

	list.insert(234);
	list.print_list();

	list.remove(234);
	list.remove(-12);
	list.print_list();

	std:: cout << "elements" << std::endl;
	std:: cout << list[0] << std::endl;
	std:: cout << list[1] << std::endl;
	std:: cout << list[2] << std::endl;
	std:: cout << list[3] << std::endl;

	std:: cout << "tail : " << list.tail() << std::endl;

}

/* ============================================================== */

int main()
{
	std::cout << "==============Linked List=============" << std::endl;

	test_int_list();

	return 0;
}


