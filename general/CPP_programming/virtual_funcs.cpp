/*
* Program to study virtual functions
*/

#include <cstdint>
#include <cstdio>
#include <iostream>

/*
* Virtual functions, override, final
*/

// =========================================
// Buffer Class
// =========================================

class Buffer {
public:

	typedef enum : uint32_t {
		TYPE_INVALID,
		TYPE_LINEAR,
		TYPE_GRAPHIC,
	} type_t;

	Buffer() = default;
	Buffer(uint32_t len, uint32_t size, type_t Type);
	Buffer(uint32_t len) : m_len(len) {}
	~Buffer();

	uint32_t getSize();
	uint32_t getLength();
	virtual type_t getType() const final;
	virtual void printBufInfo();
	static uint32_t get_destruct_count();

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
			printf("buffer Class Destruct count %u\n", get_destruct_count());
		}
	};

protected:
	uint32_t m_len{0};
	uint32_t m_size{0};
	type_t m_type{TYPE_INVALID};

private:
	static uint32_t m_destruct_count;
};

uint32_t Buffer::m_destruct_count = 0;
uint32_t Buffer::get_destruct_count()
{
	// static member function can only access
	// other static member variables
	return m_destruct_count;
}

Buffer::Buffer(uint32_t len, uint32_t size, type_t Type)
{
	printf("Buffer Constructor\n");
	m_len = len;
	m_size = size;
	m_type = Type;
}

Buffer::~Buffer()
{
	printf("Buffer Destructor\n");
	m_destruct_count++;
}

uint32_t Buffer::getSize()
{
	return m_size;
}

uint32_t Buffer::getLength()
{
	return m_len;
}

Buffer::type_t Buffer::getType() const
{
	return m_type;
}

void Buffer::printBufInfo()
{
	printf("New buffer ==============\n");
	printf("Buffer length = %u\n", this->getLength());
	printf("Buffer size = %u\n", this->getSize());
	printf("buffer Class Destruct count %u\n", get_destruct_count());
}

// =========================================
// StringRep Class
// =========================================
class StringRep {
public:
	const char *toString(uint32_t bufType)
	{
		return (bufType == Buffer::TYPE_INVALID) ? "INVALID" :
		bufType == Buffer::TYPE_GRAPHIC ? "GRAPHIC" : "LINEAR";
	}
};

// =========================================
// LinearBuffer Class
// =========================================

class LinearBuffer : public Buffer, public StringRep {
public:
	LinearBuffer(uint32_t size, uint32_t len) :
		Buffer(len, size, Buffer::TYPE_LINEAR),
		m_fd(-1)
		{
			printf("LinearBuffer Constructor\n");
		}

	int getFd();
	virtual void printBufInfo() override;
	// cannot override a final function
	//virtual type_t getType() const

private:
	int m_fd;
};

int LinearBuffer::getFd()
{
	return m_fd;
}

void LinearBuffer::printBufInfo()
{
	// base class printBufInfo()
	Buffer::printBufInfo();
	printf("fd = %d\n", m_fd);
	printf("Buffer type: %s\n", toString(m_type));
}

// =========================================
// Tests
// =========================================


int main()
{
	LinearBuffer lb(10, 20);

	// call most-derived functions
	Buffer *b = &lb;
	b->printBufInfo();
	b->getType();

	return 0;
}

