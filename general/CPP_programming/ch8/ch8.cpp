#include <iostream>
#include <string>

class Ball
{
private:
	float radius;
	std::string shape;
public:
	int color;

	Ball(std::string size) : shape("Round")
	{
		std::cout << "New Ball: " << std::endl;
		radius = (size == "big") ? 10 : 5.5;
	}

	~Ball()
	{
		std::cout << "Destructor" << color <<std::endl;
	}

	void set_color(std::string ball_color)
	{
		this->color = (ball_color == "red") ? 1 : 0;
	}

	std::string get_shape()
	{
		return shape;
	}
};

void test_class_two()
{
	Ball football("big");
	Ball tennis("small");

	football.set_color("red");
	tennis.set_color("green");

	std::cout << "Shape:" << football.get_shape() << std::endl;
}

enum mode {
	human,
	ai,
};

class Gamer
{
private:
	int mode;

public:
	int age;
	std::string name;

	void initialize(int player_mode, std::string player_name, int player_age)
	{
		mode = player_mode;
		name = player_name;
		age = player_age;
	}

	void print_info()
	{
		std::cout << "Player name: " << name << std::endl;
                std::cout << "Player age: " << age << std::endl;
		std::cout << "Player mode: " << (mode ? "AI" : "Human") << std::endl;
	}
};

void test_class()
{
	Gamer mg, cp;

	mg.initialize(human, "Player", 26);
	cp.initialize(ai, "Computer", 100);

	mg.print_info();
	cp.print_info();
}

int main()
{
	/* C++ - Basic Object-Oriented Programming */

	test_class();

	test_class_two();

	return 0;
}



