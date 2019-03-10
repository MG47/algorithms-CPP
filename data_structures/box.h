/*
* Dummy box class to test data structures
*/

#ifndef __BOX_H_
#define __BOX_H_

#include <iostream>

class Box {
	public:
		Box():
			m_height(5),
			m_width(5),
			m_length(5),
			m_id(id_counter++)
		{
			std::cout << "Box constructor : ID: " << m_id << std::endl;
		}
		Box(double ht, double wdt, double len):
			m_height(ht),
			m_width(wdt),
			m_length(len),
			m_id(id_counter++)
		{
			std::cout << "Box constructor : ID: " << m_id << std::endl;
		}
		~Box()
		{
			std::cout << "Box Destructor : ID: " << m_id << std::endl;
		}
		double get_volume()
		{
			return m_height * m_length * m_width;
		}

		double get_id()
		{
			return m_id;
		}

	private:
		static unsigned int id_counter;
		double m_id;
		double m_height;
		double m_length;
		double m_width;
};

unsigned int Box::id_counter = 0;


#endif /* __BOX_H_ */
