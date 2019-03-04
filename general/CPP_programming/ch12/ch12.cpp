#include <iostream>

class Vehicle {
	protected:
		unsigned int m_cur_speed;
		unsigned int m_max_speed;
	public:
		Vehicle()
		{

		}

		Vehicle(int speed) : m_cur_speed(0), m_max_speed(120)
		{
			m_cur_speed = speed;
		}

		virtual void accelerate();
		unsigned int get_cur_speed()
		{
			return m_cur_speed;
		}

		virtual void brake();

		virtual void start_car() final
		{

		}
};

void Vehicle::accelerate()
{
	if (m_cur_speed < m_max_speed)
		m_cur_speed++;
}

void Vehicle::brake()
{
	if (m_cur_speed)
		m_cur_speed--;

}
class Sports_car : public Vehicle {
	public:
		Sports_car(int speed)
		{
			m_cur_speed = speed;
			m_max_speed = 220;
		}
		void accelerate() override;
		void brake() override;
};

void Sports_car::accelerate()
{
	if (m_cur_speed < (m_max_speed - 5))
		m_cur_speed += 5;
}

void Sports_car::brake()
{
	if (m_cur_speed > 1)
		m_cur_speed -= 2;
}

/* ======================================= */

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
};

class Triangle: public Shape{
	public:
		Triangle(int a = 0, int b = 0) : Shape(a, b) { }
		virtual int get_area()
		{
			std::cout << "Triangle Area :" << std::endl;
			return (m_width * m_height / 2);
		}
};

class Circle: public Shape{
	public:
		Circle(int a = 0, int b = 0) : Shape(a, b) { }
		virtual int get_area()
		{
			std::cout << "Circle Area :" << std::endl;
			return (3.14 * m_width * m_width);
		}
};

int main()
{

	/* C++ - Virtual functions : virutal, override, final */

	/* Shape section */
	double area;

	Rectangle rec(10,7);
	Triangle  tri(10,5);
	Circle circ(5, 0);

	Shape &shape_1 = rec;
	area = shape_1.get_area();
	std::cout << area << std::endl;

	Shape &shape_2 = tri;
	area = shape_2.get_area();
	std::cout << area << std::endl;

	Shape &shape_3 = circ;
	area = shape_3.get_area();
	std::cout << area << std::endl;

	/* Vehicle section */

	Sports_car jaguar(60);
	Vehicle &veh = jaguar;
	std::cout << "Current speed " << veh.get_cur_speed() << std::endl;
	veh.accelerate();
	std::cout << "Current speed " << veh.get_cur_speed() << std::endl;

	veh.brake();
	std::cout << "Current speed " << veh.get_cur_speed() << std::endl;

	Sports_car &sp = jaguar;
	std::cout << "Current speed of Sport Car: " << sp.get_cur_speed() << std::endl;
	sp.brake();

	std::cout << "Current speed of Sport Car: " << sp.get_cur_speed() << std::endl;

	return 0;
}

