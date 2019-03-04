#include <iostream>

/* Class with Move constructor/assignment */
template <class T>
class Array {
	public:
		Array(unsigned int size = 0)
		{
			std::cout << "Array standard constructor" << std::endl;
			m_size = size;
			m_arr = new T[m_size];
		}

		// Copy constructor to do deep copy
		Array(Array &arr)
		{
			std::cout << "Array copy constructor" << std::endl;
			m_size = arr.m_size;
			m_arr = new T[m_size];
			for (int i = 0; i < m_size; i++)
				m_arr[i] = arr.m_arr[i];
		}

		Array(Array &&arr)
		{
			std::cout << "Array Move constructor" << std::endl;
			m_size = arr.m_size;
			m_arr = new T[m_size];
			for (int i = 0; i < m_size; i++)
				m_arr[i] = arr.m_arr[i];
		}

		~Array()
		{
			delete[] m_arr;
		}

		unsigned int len();

		// Move assignment to do deep copy
		Array& operator=(Array &arr)
		{
			if (&arr == this)
				return *this;
			std::cout << "Array Copy assignment" << std::endl;
			m_size = arr.m_size;
			m_arr = new T[m_size];
			for (int i = 0; i < m_size; i++)
				m_arr[i] = arr.m_arr[i];
			return *this;
		}

		Array& operator=(Array &&arr)
		{
			if (&arr == this)
				return *this;
			std::cout << "Array Move assignment" << std::endl;
			m_size = arr.m_size;
			m_arr = new T[m_size];
			for (int i = 0; i < m_size; i++)
				m_arr[i] = arr.m_arr[i];
			return *this;
		}

		T& operator[](unsigned int index);

	private:
		T *m_arr;
		unsigned int m_size;
};

template <class T>
unsigned int Array<T>::len()
{
	return m_size;
}

template <class T>
T& Array<T>::operator[](unsigned int index)
{
	if (index < m_size)
		return m_arr[index];
	std::cout << "Array index out of bounds";
	return m_arr[0];
}

//helper
Array<double>& clone(Array<double> &arr)
{
	Array<double> new_arr(*(new Array<double>));
	return new_arr;
}

int main ()
{
	// TODO
	/* C++ - Move semantics TODO */

	/* Integer Array class */
	Array<int> my_int_arr(10);

	for (int i = 0; i < my_int_arr.len(); i++)
		std::cout << i << ":" << my_int_arr[i] << std::endl;


	for (int i = 0; i < my_int_arr.len(); i++) {
		my_int_arr[i] = i * 10;
		std::cout << i << ":" << my_int_arr[i] << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << std::endl << std::endl;

	/* Double Array class */
	Array<double> my_double_arr(10);

	for (int i = 0; i < my_double_arr.len(); i++)
		std::cout << i << ":" << my_double_arr[i] << std::endl;

	for (int i = 0; i < my_double_arr.len(); i++) {
		my_double_arr[i] = i * 10.2;
		std::cout << i << ":" << my_double_arr[i] << std::endl;
	}

	std::cout << std::endl << std::endl;

	// Calls both constructor (for temp obj) and copy constructor
	Array<double> my_double_arr_second;
	my_double_arr_second = clone(my_double_arr);
	for (int i = 0; i < my_double_arr_second.len(); i++) {
		std::cout << i << ":" << my_double_arr_second[i] << std::endl;
	}

#if 0
	for (int i = 0; i < my_double_arr.len(); i++) {
		my_double_arr[i] = i * 100.2;
		std::cout << i << ":" << my_double_arr[i] << std::endl;
	}

	my_double_arr_second = clone(my_double_arr);
	for (int i = 0; i < my_double_arr_second.len(); i++) {
		std::cout << i << ":" << my_double_arr_second[i] << std::endl;
	}

#endif
#if 0
	/* Another double array using copy assignment */
	Array<double> my_double_arr_third = my_double_arr_second;
	for (int i = 0; i < my_double_arr_third.len(); i++) {
		std::cout << i << ":" << my_double_arr_third[i] << std::endl;
	}
#endif
	return 0;
}

