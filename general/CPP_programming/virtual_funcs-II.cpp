/*
* Program to study virtual functions - PART II
*/

#include <iostream>

/*
* Pure virtual functions
* Abstract classes, interface class
* Dynamic cast
*/

// =========================================
// IVehicle interface class
// =========================================

class IVehicle {
	public:

		virtual void accelerate() = 0;
		virtual void brake() = 0;
		virtual unsigned int getCurSpeed() = 0;
		virtual void startCar() = 0;
		virtual void printCarStats() = 0;
		// virtual destructor
		virtual ~IVehicle() {}
};

// =========================================
// IVehicle interface class
// =========================================

class SportsCar : public IVehicle {
	public:
		SportsCar() = default;
		SportsCar(uint32_t speed, std::string name) :
			m_cur_speed(speed),
			m_name(name) {}

		virtual void accelerate() override;
		virtual void brake() override;
		virtual unsigned int getCurSpeed() override;
		virtual void startCar() override;
		virtual void printCarStats() override;

	protected:
		uint32_t m_cur_speed{0};
		uint32_t m_max_speed{220};
		std::string m_name;
};

void SportsCar::accelerate()
{
	if (m_cur_speed < (m_max_speed - 5))
		m_cur_speed += 5;
}

void SportsCar::brake()
{
	if (m_cur_speed > 1)
		m_cur_speed -= 2;
}

unsigned int SportsCar::getCurSpeed()
{
	return m_cur_speed;
}

void SportsCar::startCar()
{

}

void SportsCar::printCarStats()
{
	printf("============== \n");
	printf("Sports Car %s \n", m_name.c_str());
	printf("Max speed = %u\n", m_max_speed);
	printf("Current speed = %u\n", m_cur_speed);
}


/* ======================================= */

// =========================================
// Buffer Class - abstract class
// =========================================

class Buffer {
public:

	typedef enum : uint32_t {
		TYPE_INVALID,
		TYPE_LINEAR,
		TYPE_GRAPHIC,
	} type_t;

	Buffer(uint32_t len, uint32_t size, type_t Type);
	~Buffer() = default;

	virtual uint32_t getSize()
	{
		return m_size;
	};

	// Pure virtual functions
	virtual uint32_t getLength() = 0;
	virtual type_t getType() const = 0;

	// Pure virtual function, body is defined separately
	virtual void printBufInfo() = 0;

	// Nested class
	class BufferPrinter {
	public:
		void print(Buffer &buf)
		{
			printf("New buffer ==============\n");
			printf("Buffer length = %u\n", buf.getLength());
			printf("Buffer size = %u\n", buf.getSize());
			printf("Buffer type = %s\n",
				(buf.getType() == TYPE_INVALID) ? "INVALID" :
				buf.getType() == TYPE_GRAPHIC ? "GRAPHIC" : "LINEAR");
		}
	};

protected:
	uint32_t m_len{0};
	uint32_t m_size{0};
	type_t m_type{TYPE_INVALID};

private:
};

Buffer::Buffer(uint32_t len, uint32_t size, type_t Type)
{
	printf("Buffer Constructor\n");
	m_len = len;
	m_size = size;
	m_type = Type;
}

// Pure virtual function can have a body
void Buffer::printBufInfo()
{
	printf("New buffer ==============\n");
	printf("Buffer length = %u\n", this->getLength());
	printf("Buffer size = %u\n", this->getSize());
}

// =========================================
// LinearBuffer Class
// =========================================

class LinearBuffer : public Buffer {
public:
	LinearBuffer(uint32_t size, uint32_t len) :
		Buffer(len, size, Buffer::TYPE_LINEAR),
		m_fd(-1)
		{
			printf("LinearBuffer Constructor\n");
		}

	// Pure virtual functions
	virtual uint32_t getSize() override;
	virtual uint32_t getLength() override;
	virtual type_t getType() const override;
	virtual void printBufInfo() override;

	int getFd();
	// cannot override a final function
	//virtual type_t getType() const

private:
	int m_fd;
};


uint32_t LinearBuffer::getSize()
{
	return m_size;
}

uint32_t LinearBuffer::getLength()
{
	return m_len;
}

Buffer::type_t LinearBuffer::getType() const
{
	return m_type;
}

int LinearBuffer::getFd()
{
	return m_fd;
}

void LinearBuffer::printBufInfo()
{
	// base class printBufInfo()
	Buffer::printBufInfo();
	printf("fd = %d\n", m_fd);
	printf("Buffer type: %s\n",
		(m_type == Buffer::TYPE_INVALID) ? "INVALID" :
		m_type == Buffer::TYPE_GRAPHIC ? "GRAPHIC" : "LINEAR");
}

// =========================================
// Tests
// =========================================

int main()
{
	// test abstract class
	// cannot instatitate abstract class
	// Buffer b;

	LinearBuffer *lb = new LinearBuffer(10, 20);

	Buffer *b = lb;
	b->printBufInfo();
	b->getType();

	// dynamic casting - TODO

	// test interface class
	IVehicle *jaguar = new SportsCar(10, "Jaguar");
	jaguar->printCarStats();

	return 0;
}

