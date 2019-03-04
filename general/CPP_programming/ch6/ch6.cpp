#include <algorithm>
#include <iostream>

void test_reference_arg(int &arg)
{
	arg--;
}

void change_array(int (&arr)[3])
{
	int len = sizeof(arr)/sizeof(arr[0]);

	arr[2] = 10;

	std::cout << "len = " << len << " arr[2] = " << arr[2] << std::endl;
}

void test_references()
{
	using namespace std;

	int a(5);

	int &ref_a = a;

	cout << "value of a " << a << endl;
	cout << "ref_a = " << ref_a << endl;

	ref_a++;

        cout << "value of a " << a << endl;

	test_reference_arg(a);

        cout << "value of a " << a << endl;


	const int my_const(19);

	const int &my_const_ref = my_const;

        cout << "value of my_const " << my_const << endl;

	const int &my_constant_ref = 10;

        cout << "value of my_const " << my_const << endl;

	int my_arr[] = {3, 4, 5};

	change_array(my_arr);
}

void test_alloc()
{
	using namespace std;

	int *a_ptr = new int(10);

	cout << "new int ptr " << a_ptr << " and value " <<*a_ptr << endl;

	char *ch = new char('c');

	cout << "new char : " << ch << endl;


	//allocate an array of ints
	int *arr = new int[20];

	delete a_ptr;
	delete ch;
	delete[] arr;
}

void test_nullptr()
{
        // initialize as nullptr
//        int *ptr(nullptr);
//        std::cout << "value of ptr is " << ptr << std::endl;
}

void test_sort()
{
	using namespace std;
	const int arr_len = 5;

	int arr[arr_len] = {98, 2, 1, 15, 3};

	cout << "Arr before sorting "<< endl;

	for (int i = 0; i < arr_len; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	// std::sort()
	sort(arr, arr + arr_len);
        cout << "Arr after sorting "<< endl;

        for (int i = 0; i < arr_len; i++) {
                cout << "arr[" << i << "] = " << arr[i] << endl;
        }
}

int main()
{
	/* C++ - Arrays, vectors, nullptr, references  */

	test_sort();

	test_nullptr();

	test_alloc();

	test_references();

	return 0;
}
