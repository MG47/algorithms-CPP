/*
* Program to study templates
*/

#include <stdio.h>
#include <string.h>
/*
* PART I:
* function templates
* function template specialization
*/

class Box {
	public:
		Box(double vol) : m_volume(vol)
		{}
		double get_volume()
		{
			return m_volume;
		}

		friend Box operator+(Box B1, Box B2)
		{
			Box B(0);
			B.m_volume = B1.m_volume + B2.m_volume;
			return B;
		}

	private:
		double m_volume;
};

template <typename T>
T adder(T *first, T *second)
{
	if (first && second)
		return *first + *second;
	return 0;
}

template <typename T>
void copy(T *dst, T *src)
{
	if (dst && src)
		*dst = *src;
}

/* function template specialization */
template <>
void copy(char* dest, char* src)
{
	char *source = src;
	if (!src)
		return;

	unsigned int len = 0;
	while (*src++)
		len++;
	len++;

	if (!dest)
		dest = new char[len];

	memcpy(dest, source, sizeof(char) * len);
	return;
}

int main()
{
	/* C++ - Templates */

	int a = 3, b = 4;
	copy(&b, &a);
	printf("a = %d, b = %d\n", a, b);

	double c = 3.2, d = 41.2;
	copy(&d, &c);
	printf("d = %f, c = %f\n", d, c);

	Box b1(10), b2(22);
	Box b3 = b1 + b2;
	printf("Volume of box b3 = %f\n", b3.get_volume());

	return 0;
}

