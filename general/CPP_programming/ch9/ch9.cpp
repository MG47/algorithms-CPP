#include <iostream>

class Box
{
	public:
		Box();
		Box(double m_height, double m_width, double m_length);

		double get_height();
		double get_width();
		double get_length();
		double get_volume() const;

	private:
		double m_width;
		double m_length;
		double m_height;
		double m_volume;

};

// default constructor
Box::Box() : m_height(20.0), m_width(10.0), m_length(5.0)
{
	m_volume = m_height * m_width * m_length;
}

Box::Box(double m_height, double m_width, double m_length)
{
	this->m_height = m_height;
	this->m_width = m_width;
	this->m_length = m_length;
	this->m_volume = m_height * m_width * m_length;
}

double Box::get_height()
{
	return m_height;
}

double Box::get_width()
{
	return m_width;
}

double Box::get_length()
{
	return m_length;
}

double Box::get_volume() const
{
	return m_volume;
}

double operator+(const Box &b1, const Box &b2)
{
	return b1.get_volume() + b2.get_volume();
}

double operator+(const Box &b1, double volume)
{
	return b1.get_volume() + volume;
}

double operator+(double volume, const Box &b2)
{
	return volume + b2.get_volume();
}

int main(void)
{
	/* C++ - Operator overloading */

	Box mybox(20.0, 50.0, 70.0);
	Box secondbox;

	// Add volumes
	double total_volume;
	total_volume = mybox + secondbox;
	std::cout << "Volume addition  = " << total_volume << std::endl;

	total_volume = mybox + 30;
	std::cout << "Volume addition  = " << total_volume << std::endl;

	total_volume = 40 + secondbox;
	std::cout << "Volume addition  = " << total_volume << std::endl;

	return 0;
}

