#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <initializer_list>


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
		void print_cvec();

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

void Cvector::print_cvec()
{
	for (int i = 0; i < m_len; i++)
		std::cout << m_arr[i] << std::endl;
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

// Container class for Cvectors
class CvectorArr {
	public:
		CvectorArr();
		CvectorArr(const std::initializer_list<Cvector> &list);
		~CvectorArr();

		void add(const Cvector &vec);
		void clear();
		void print_arr();

	private:
		int m_len;
		Cvector *m_arr;
};

CvectorArr::CvectorArr() : m_arr(NULL), m_len(0)
{
	delete m_arr;
}

// Initialize using intializer list
CvectorArr::CvectorArr(const std::initializer_list<Cvector> &list)
{
	std::cout << "initilize using intilzier list" << std::endl;
	m_len = 0;
	m_arr = NULL;
	m_arr = (Cvector *)realloc(m_arr, m_len * sizeof(Cvector));

	for (auto &element : list)
	{
		m_arr[m_len] = element;
		++m_len;
	}
}

CvectorArr::~CvectorArr()
{

}

void CvectorArr::add(const Cvector &vec)
{
	m_len++;
	m_arr = (Cvector *)realloc(m_arr, m_len * sizeof(Cvector));
	m_arr[m_len - 1] = vec;
}

void CvectorArr::clear()
{
	delete m_arr;
	m_arr = NULL;
}

void CvectorArr::print_arr()
{
	for (int i = 0; i < m_len; i++) {
		m_arr->print_cvec();
		std::cout << std::endl;
	}
}

int main(void)
{
	/* C++ - Container classes, initializer list  */
	Cvector vec(20);

	for (int i = 0; i < vec.len(); i++)
		vec[i] = i * 2;

	for (int i = 0; i < vec.len(); i++)
		std::cout << vec[i] << std::endl;

	// Using copy constructor
	Cvector my_vec2(vec);
	for (int i = 0; i < my_vec2.len(); i++)
		std::cout << my_vec2[i] << std::endl;

	// Using assignment operator
	Cvector my_vec4 = my_vec2;
	for (int i = 0; i < my_vec4.len(); i++)
		std::cout << my_vec4[i] << std::endl;

	// Create a container object;
	CvectorArr vec_arr;
	vec_arr.add(vec);
	vec_arr.add(my_vec2);
	vec_arr.add(my_vec4);

	vec_arr.print_arr();

	// initialize using intializer list
	CvectorArr vec_arr_two {vec, my_vec2, my_vec4};

	vec_arr_two.print_arr();

	return 0;
}

