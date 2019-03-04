#include <iostream>

class Box
{
	public:
		Box();
		Box(double m_height, double m_width, double m_length);

		void set_width(double wid);

		// Const member function
		double get_length() const;

		// static member variable
		static int num_of_objs;

		// static member function;
		static int get_no_of_objs();

		// friend function
		friend double get_volume(const Box &box);

		// friend class
		friend class Box_helper;

	private:
		double m_width;
		double m_length;
		double m_height;

};

Box::Box() : m_height(20.0), m_width(10.0), m_length(5.0)
{
	num_of_objs++;
}

Box::Box(double m_height, double m_width, double m_length)
{
	this->m_height = m_height;
	this->m_width = m_width;
	this->m_length = m_length;
	num_of_objs++;
}

void Box::set_width(double m_width)
{
	this->m_width = m_width;
}

double Box::get_length() const
{
	return m_length;
}

// static member variable
int Box::num_of_objs = 0;

// static member function

int Box::get_no_of_objs()
{
	return num_of_objs;
}

// friend function
double get_volume(const Box &box)
{
	return box.m_height * box.m_width * box.m_length;
}

// Friend class
class Box_helper
{
	public:
		void print_volume(const Box &box);
};

void Box_helper::print_volume(const Box &box)
{
	std::cout << "Volume of the box is : "
	<< box.m_height * box.m_width * box.m_length << std::endl;
}

int main(void)
{
	/* C++ - 'this', friend , static var/function, const obj*/

	// Set m_height using 'this' pointer
	Box mybox(20.0, 50.0, 70.0);

	// const obj
	const Box myconstbox;
	std:: cout << "myconstbox len = " << myconstbox.get_length() << std::endl;

	// Illegal, as myconstbox is const obj
	//myconstbox.setm_width(50.0);

	//  static member variable
	std::cout << "total no of objects of Box = " << Box::num_of_objs << std::endl;

	//static member function
	std::cout << "total no of objects of Box = " << Box::get_no_of_objs() << std::endl;

	// friend function
	std::cout << "Volume of mybox = " << get_volume(mybox) << std::endl;

	// friend class
	Box_helper bh;
	bh.print_volume(mybox);

	return 0;
}

