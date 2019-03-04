#include <iostream>
#include <string.h>

template <typename T>
T* copy(T* dest, T* src)
{
	*dest = *src;
	return dest;
}

template <>
char *copy(char* dest, char* src)
{
	char *source = src;
	if (!src)
		return NULL;

	unsigned int len = 0;
	while (*src++)
		len++;
	len++;

	dest = new char[len];

	memcpy(dest, source, sizeof(char) * len);
	return dest;
}

/* ============================================== */

int main(void)
{
	/* C++ - Template function specialization */

	int a = 10, b = 0;
	copy(&b, &a);
	std::cout << "a = " << a << " b = " << b << std::endl;

	double c = 10.2, d = 0.0;
	copy(&d, &c);
	std::cout << "c = " << c << " d = " << d << std::endl;

	/* Need to do deep copy for (char *) */
	char *e = new char[6], *f;
	std::cin >> e;
	f = copy(f, e);
	std::cout << "e = " << e << std::endl;
	delete[] e;
	std::cout << "f = " << f << std::endl;

	return 0;
}
