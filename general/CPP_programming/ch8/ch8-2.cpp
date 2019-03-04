#include <iostream>

/* =================================== */

class Circle
{
	public:
		Circle(double di);
		~Circle();

		void set_diameter(double diameter);
		double get_diameter();

	private:
		double diameter;
};

/* Constructor - member initializer list */
Circle::Circle(double di) : diameter(di)
{
	std::cout << "creating Cirlce object, diameter  = " << diameter << std::endl;
}

#if 0
TODO
Circle::Circle(const &cpy)
{

}
#endif

Circle::~Circle()
{
	std::cout << "Destroying Cirlce object" << std::endl;
}

double Circle::get_diameter()
{
	return diameter;
}

void Circle::set_diameter(double di)
{
	diameter = di;
}

/* =================================== */

/* Class Line */
class Line
{
	public:
		Line(); 	   		// Default constructor
		Line(double len);  		// Constructor
		~Line();  			// Destructor

		void set_length(double len);
		double get_length(void);

	private:
		double length;
};

Line::Line()
{
	std::cout << "Default constructor : Object is being created " << std::endl;
	length = 10.0;
}

Line::Line(double len)
{
	std::cout << "Object Line is being created" << std::endl;

	length = len;
}

Line::~Line(void)
{
	std::cout << "Object is being deleted" << std::endl;
}

void Line::set_length(double len)
{
	length = len;
}

double Line::get_length(void)
{
	return length;
}
/*=====================================*/


int main( )
{
	/* C++ - Constructors, destructors, default constructors */

	Line line_one;
	std::cout << "Length of line_one : " << line_one.get_length() << std::endl;

	line_one.set_length(3.0);
	std::cout << "Length of line_one : " << line_one.get_length() << std::endl;
	std::cout << "\n\n\n";

	Line line_two(20.0);
	std::cout << "Length of line_two : " << line_two.get_length() << std::endl;

	line_two.set_length(6.0);
	std::cout << "Length of line_two : " << line_two.get_length() << std::endl;
	std::cout << "\n\n\n";

	Circle circle(5.0);
	std::cout << "Diameter of circle = " << circle.get_diameter() << std::endl;
	std::cout << "\n\n\n";

	return 0;
}

