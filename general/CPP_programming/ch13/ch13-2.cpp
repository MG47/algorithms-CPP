#include <iostream>
#include <stdlib.h>
#include <string.h>

// Custom vector class template
template <class T>
class Cvector {
	public:
		Cvector();
		Cvector(int len);
		~Cvector();

		int len();
		T &operator[](int index);

	private:
		T *m_arr;
		int m_len;
};

template <class T>
Cvector<T>::Cvector()
{
	m_len = 10;
	m_arr = (T *)calloc(m_len, sizeof(int));
}

template <class T>
Cvector<T>::Cvector(int len)
{
	m_len = len;
	m_arr = (T *)calloc(m_len, sizeof(T));
}

template <class T>
Cvector<T>::~Cvector()
{
	if (m_arr)
		free(m_arr);
}

template <class T>
int Cvector<T>::len()
{
	return m_len;
}

template <class T>
T &Cvector<T>::operator[](int index)
{
	//TODO handle error
	if (index < m_len)
		return m_arr[index];
	return m_arr[0];
}


/* ============================================== */

// Custom array class template

template <class T, int size>
class Array {
	public:
		unsigned int len();
		T *NewArray();
		T &operator[](unsigned int index);
	private:
		T m_arr[size];
};

template <class T, int size>
T *Array<T,size>::NewArray()
{
	return m_arr;
}

template <class T, int size>
unsigned int Array<T, size>::len()
{
	return size;
}

template <class T, int size>
T &Array<T, size>::operator[](unsigned int index)
{
	if (index < size)
		return m_arr[index];
	std::cout << "Array index out of bounds!" << std::endl;
	exit(EXIT_FAILURE);
}

/* ============================================== */

int main(void)
{
	/* C++ - Template classes, non-type template parameters*/

	Cvector<int> vec_int(20);

	for (int i = 0; i < vec_int.len(); i++)
		vec_int[i] = i * 2;

	for (int i = 0; i < vec_int.len(); i++)
		std::cout << vec_int[i] << std::endl;

	Cvector<double> vec_d(20);

	for (int i = 0; i < vec_d.len(); i++)
		vec_d[i] = i * 2.5;

	for (int i = 0; i < vec_d.len(); i++)
		std::cout << vec_d[i] << std::endl;


	// Array section
	Array<int, 10> my_arr;
	for (int i = 0; i < my_arr.len(); i++)
		my_arr[i] = i * 10;

	for (int i = 0; i < my_arr.len(); i++)
		std::cout << my_arr[i] << std::endl;

	Array<double, 30> my_d_arr;
	for (int i = 0; i < my_d_arr.len(); i++)
		my_d_arr[i] = i * 10.5;

	for (int i = 0; i < my_d_arr.len(); i++)
		std::cout << my_d_arr[i] << std::endl;


	return 0;
}

