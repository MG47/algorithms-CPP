#include <iostream>

class Equipment
{
	protected:
		unsigned int m_id;
	public:
		Equipment() : m_id(0)
		{

		}
		unsigned int get_id()
		{
			return m_id;
		}
};

class Ball
{
	private:
		double m_diameter;
		int m_color;

	public:

		enum color {
			RED,
			WHITE,
			GREEN,
		};

		void set_color(int color_code);
		int get_color();
};

void Ball::set_color(int color_code)
{
	m_color = color_code;
}

int Ball::get_color()
{
	return m_color;
}

class TennisBall : public Ball, public Equipment
{
	private:
		std::string m_type;
	public:

		TennisBall() : m_type("Tennis")
		{

		}
		std::string get_type()
		{
			return m_type;
		}
};

/* ========================================================== */

class Box
{
	protected:
		double my_length;

	public:
		double m_length;         // Length of a box
		double m_breadth;        // Breadth of a box
		double m_height;         // Height of a box

		// Member functions declaration
		double get_volume();
		void set_length(double length);
		void set_breadth(double breadth);
		void set_height(double height);
		std::string get_box_type();
};

double Box::get_volume()
{
	return m_length * m_breadth * m_height;
}

void Box::set_length(double length)
{
	m_length = length;
}

void Box::set_breadth(double breadth)
{
	m_breadth = breadth;
}

void Box::set_height(double height)
{
	m_height = height;
}

std::string Box::get_box_type()
{
	return "box";
}

class GiftBox: public Box
{
	public:
		GiftBox() : m_recipient("Anonymous")
		{
		}

		void set_recipient(std::string new_recipient);
		double get_volume();

		void set_length(double length) = delete;
		void set_breadth(double breadth) = delete;
		void set_height(double height) = delete;
		std::string get_box_type();

	private:
		std::string m_recipient;
};

double GiftBox::get_volume()
{
	return 8;
}

void GiftBox::set_recipient(std::string new_recipient)
{
	m_recipient = new_recipient;
}

std::string GiftBox::get_box_type()
{
	return "small " + Box::get_box_type();
}

int main( )
{
	/* C++ - Inheritance : access specifiers, derived classes, multiple inheritance */

	/* Box section */
	Box box1;
	Box box2;
	double volume = 0.0;

	box1.set_length(6.0);
	box1.set_breadth(7.0);
	box1.set_height(5.0);

	box2.set_length(12.0);
	box2.set_breadth(13.0);
	box2.set_height(10.0);

	volume = box1.get_volume();
	std::cout << "Volume of box1 : " << volume << std::endl;

	volume = box2.get_volume();
	std::cout << "Volume of box2 : " << volume << std::endl;
	std::cout << "Type: " << box2.get_box_type() << std::endl;

	GiftBox gbox;

	gbox.set_recipient("Mihir");
	std::cout << "Volume of gbox : " << gbox.get_volume() << std::endl;
	std::cout << "Type: " << gbox.get_box_type() << std::endl;

	/* Ball section */
	TennisBall tb;

	tb.set_color(Ball::GREEN);
	std::cout << "color code of ball: " << tb.get_color() << std::endl;

	std::cout << "ID: " << tb.get_id() << std::endl;
	std::cout << "Type: " << tb.get_type() << std::endl;
	std::cout << "color code of tennis ball: " << tb.get_color() << std::endl;


	return 0;
}

