#include <iostream>

/* Interface Class */
class IHuman {
	public:
		virtual void run();
		virtual void talk();
		virtual void breath();
		IHuman();
		virtual ~IHuman();
};

class Male : public IHuman {
	public:
		void run()
		{
			return;
		}
		void talk()
		{
			return;
		}
		void breath()
		{
			return;
		}
		virtual ~Male()
		{

		}
};

class Female : public IHuman {
	public:
		void run()
		{
			return;
		}
		void talk()
		{
			return;
		}
		void breath()
		{
			return;
		}
		virtual ~Female()
		{

		}
};
/* Abstract class */
class Animal {
	public:
		Animal() :  m_kingdom("Animalia")
		{}
		~Animal()
		{}

		virtual std::string make_sound() = 0;
	protected:
		const std::string m_kingdom;
};

class Mammal : public Animal {

	public:
		virtual std::string make_sound()
		{
			return "Grrrrr";
		}

};

class Shape {
	protected:
		int m_width, m_height;
		double m_area;
	public:
		Shape(int a = 0, int b = 0)
		{
			m_width = a;
			m_height = b;
		}

		virtual ~Shape()
		{
			std::cout << "Destr for Shape" << std::endl;
		}

		virtual int get_area()
		{
			std::cout << "Parent class area :" << std::endl;
			return 0;
		}
};

class Rectangle: public Shape{
	public:
		Rectangle( int a = 0, int b = 0) : Shape(a, b) { }
		virtual int get_area()
		{
			std::cout << "Rectangle Area :" << std::endl;
			return (m_width * m_height);
		}
		virtual ~Rectangle()
		{
			std::cout << "Destr for Rectangle" << std::endl;
		}
};

int main()
{

	/* C++ - Virtual functions : virtual destructors,
	pure virtual functions, abstract classes, interface classes */

	/* Shape section */
	double area;
	Rectangle rec(10,7);

	Shape &shape_1 = rec;
	area = shape_1.get_area();
	std::cout << area << std::endl;

	/* Animal section */
	Mammal leo;
	Animal &a1 = leo;

	/* Human section */

	return 0;
}

