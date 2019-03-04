#include <iostream>

class PaintCost
{
	public:
		int getCost(int area)
		{
			return area * 70;
		}
};

// Base class
class Shape
{
	public:
		Shape(int width, int height) :
		m_width(5), m_height(5)
		{
			m_width = width;
			m_height = height;
		}

		void setWidth(int w)
		{
			m_width = w;
		}
		void setHeight(int h)
		{
			m_height = h;
		}
	protected:
		int m_width;
		int m_height;
};

// Derived class
class Rectangle: public Shape, public PaintCost
{
	public:
		Rectangle() : Shape(10, 10)
		{

		}

		int getArea()
		{
			return (m_width * m_height);
		}
};

int main(void)
{
	/* C++ - Inheritance */

	Rectangle Rect;

	Rect.setWidth(5);
	Rect.setHeight(7);

	// Print the area of the object.
	std::cout << "Total area: " << Rect.getArea() << std::endl;

	// Print the cost of the object.
	std::cout << "Total cost: " << Rect.getCost(Rect.getArea()) << std::endl;

	Rectangle Rect2;
	// Print the area of the object.
	std::cout << "Total area: " << Rect2.getArea() << std::endl;

	// Print the cost of the object.
	std::cout << "Total cost: " << Rect2.getCost(Rect2.getArea()) << std::endl;

	return 0;
}

