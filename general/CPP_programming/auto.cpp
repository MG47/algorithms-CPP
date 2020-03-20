/*
* Program to study 'auto'
*/

#include <cstdio>
#include <vector>


#if 0

// TODO : for C++14 and later only
auto print_vector(std::vector<int> *v)
{
	return v;
}

// TODO for C++20 and later only
Starting in C++20, the auto keyword can be used as a shorthand way to create function templates
auto add(auto x, auto y)
{
	return x + y;
}
#endif

struct car {
	double top_speed;
	bool is_electric;
};

std::vector<double> &print(std::vector<double> &v)
{

	for (auto const &i : v)
		printf("%f\n", v[i]);

	return v;
}

std::vector<car> &init_cars(std::vector<car> &c)
{
	for (auto i = 0; i < 5; i++) {
		struct car nc;
		nc.top_speed = 100 + i * 5;
		nc.is_electric = (i % 2) ? true : false;
		c.push_back(nc);
	}

	return c;
}

int main()
{
	auto i = 3;
	auto d = 3.5;

	printf("i = %d\n", i);
	printf("d = %f\n", d);

	std::vector<double> vec;

	// auto type
	for (auto i = 0.2; i < 10; i++)
		vec.push_back(i);

	// automatic type deduction
	auto v = print(vec);

	std::vector<car> c;

	// automatic type deduction
	auto cars = init_cars(c);
	for (auto i : c) {
		printf("top_speed %f\n", i.top_speed);
		printf("Electric : %s\n", i.is_electric? "YES" : "NO");
		printf("\n\n");
	}

	return 0;
}

