#include <iostream>
#include <memory>

template <class T, unsigned int size>
class Array {
	public:
		Array()
		{
			std::cout << "Array standard constructor" << std::endl;
			m_size = size;
			m_arr = new T[m_size];
		}

		~Array()
		{
			std::cout << "Array destructor" << std::endl;
			delete[] m_arr;
		}

		unsigned int len();

		T& operator[](unsigned int index);

	private:
		T *m_arr;
		unsigned int m_size;
};

template <class T, unsigned int size>
unsigned int Array<T, size>::len()
{
	return m_size;
}

template <class T, unsigned int size>
T& Array<T, size>::operator[](unsigned int index)
{
	if (index < m_size)
		return m_arr[index];
	std::cout << "Array index out of bounds";
	return m_arr[0];
}

void test_shared_ptr_sharing(std::shared_ptr<Array<int, 10>> my_arr_ptr)
{
	std::shared_ptr<Array<int, 10>> my_second_arr_ptr(my_arr_ptr);
	std::cout << "my_second_arr_ptr is "  << (my_second_arr_ptr ? "Not null" : "null") << std::endl;

	for (int i = 0; i < ((*my_second_arr_ptr).len()); i++)
		(*my_second_arr_ptr)[i] = i * 2;
}

void test_shared_ptr()
{
	std::shared_ptr<Array<int, 10>> my_arr_ptr(new Array<int, 10>);
	std::cout << "my_arr_ptr is "  << (my_arr_ptr ? "Not null" : "null") << std::endl;

	for (int i = 0; i < ((*my_arr_ptr).len()); i++)
		std::cout << i << ":" << (*my_arr_ptr)[i] << std::endl;

	test_shared_ptr_sharing(my_arr_ptr);

	for (int i = 0; i < ((*my_arr_ptr).len()); i++)
		std::cout << i << ":" << (*my_arr_ptr)[i] << std::endl;
}

void test_unique_ptr()
{
	std::unique_ptr<Array<double, 10>> my_arr_ptr(new Array<double, 10>);
	std::unique_ptr<Array<double, 10>> my_second_arr_ptr; //null init

	std::cout << "my_arr_ptr is "  << (my_arr_ptr ? "Not null" : "null") << std::endl;
	std::cout << "my_second_arr_ptr is "  << (my_second_arr_ptr ? "Not null" : "null") << std::endl;

	my_second_arr_ptr = std::move(my_arr_ptr);

	std::cout << "my_arr_ptr is "  << (my_arr_ptr ? "Not null" : "null") << std::endl;
	std::cout << "my_second_arr_ptr is "  << (my_second_arr_ptr ? "Not null" : "null") << std::endl;

	// Access elements
	for (int i = 0; i < ((*my_second_arr_ptr).len()); i++)
		std::cout << i << ":" << (*my_second_arr_ptr)[i] << std::endl;

	for (int i = 0; i < ((*my_second_arr_ptr).len()); i++) {
		(*my_second_arr_ptr)[i] = i * 2.5;
		std::cout << i << ":" << (*my_second_arr_ptr)[i] << std::endl;
	}
}

int main ()
{
	/* C++ - std:: unique_ptr, shared_ptr, move */
	std::cout << "Test unique ptr" << std::endl;
	test_unique_ptr();

	std::cout << "\n\n";
	std::cout << "Test shared ptr" << std::endl;
	test_shared_ptr();

	return 0;
}

