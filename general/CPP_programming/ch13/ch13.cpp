#include <iostream>
#include <string>

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

/* Function templates */
template <typename T>
inline T const& Max (T const& a, T const& b)
{
	return a < b ? b:a;
}

template <typename T>
T adder(T num1, T num2)
{
	return num1 + num2;
}

int main()
{
	/* C++ - Templates */

	int a = int();
	std::cout << "a = " << a << std::endl;

	int i = 39;
	int j = 20;
	std::cout << "Max(i, j): " << Max(i, j) << std::endl;

	double d1 = 13.5;
	double d2 = 20.7;
	std::cout << "Max(f1, f2): " << Max(d1, d2) << std::endl;

	std::string s1 = "Hello";
	std::string s2 = "World";
	std::cout << "Max(s1, s2): " << Max(s1, s2) << std::endl;

	int sum_i = adder(10, 20);
	std::cout << "sum of ints is " << sum_i << std::endl;

	double sum_d = adder(10.0, 20.0);
	std::cout << "sum of doubles is " << sum_d << std::endl;

	Box B1(10), B2(50);
	Box B3 = adder(B1, B2);
	std::cout << "sum of box volumes is " << B3.get_volume() << std::endl;

	return 0;
}

