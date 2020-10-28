/*
* Custom Vector TODO
*/

#include <cstdio>
#include <stdlib.h>
#include <string.h>

// Custom vector class
class Cvector {
	public:
		Cvector();
		Cvector(int len);
		Cvector(const Cvector &vec);
		~Cvector();

		int len();
		int &operator[] (int index);
		Cvector &operator=(const Cvector &cvec);

	private:
		int *m_arr;
		int m_len;
};

Cvector::Cvector()
{
	m_len = 10;
	m_arr = (int *)calloc(m_len, sizeof(int));
}

Cvector::Cvector(int len)
{
	m_len = len;
	m_arr = (int *)calloc(m_len, sizeof(int));
}

// Copy constructor
Cvector::Cvector(const Cvector &cvect)
{
	m_len = cvect.m_len;

	// deep copy
	m_arr = (int *)calloc(m_len, sizeof(int));
	memcpy(m_arr, cvect.m_arr, m_len * sizeof(int));
}

Cvector::~Cvector()
{
	if (m_arr)
		free(m_arr);
}

int Cvector::len()
{
	return m_len;
}

int &Cvector::operator[](int index)
{
	//TODO handle error
	if (index < m_len)
		return m_arr[index];
	return m_arr[0];
}

Cvector &Cvector::operator=(const Cvector &cvec)
{
	// self-assignment check
	if (this == &cvec)
		return *this;

	m_len = cvec.m_len;
	m_arr = (int *)calloc(m_len, sizeof(int));
	memcpy(m_arr, cvec.m_arr, m_len * sizeof(int));
	return *this;
}

int main(void)
{
	/* C++ - Operator overloading, copy constructor, deep copy  */
	Cvector vec(20);

	for (int i = 0; i < vec.len(); i++)
		vec[i] = i * 2;

	for (int i = 0; i < vec.len(); i++)
		printf("%d\n", vec[i]);

	// Using copy constructor
	Cvector my_vec2(vec);
	for (int i = 0; i < my_vec2.len(); i++)
		printf("%d\n", vec[i]);

	// Using assignment operator
	Cvector my_vec4 = my_vec2;
	for (int i = 0; i < my_vec4.len(); i++)
		printf("%d\n", vec[i]);

	return 0;
}

