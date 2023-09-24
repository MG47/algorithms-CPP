/*
* Program to study classes - PART II
*/

#include <cstdint>
#include <cstdio>


/*
* PART II:
* Copy constructor/Initialization, default
* overloaded assignment operator
* deep copying, copy elision
* explicit, delete
*/


// =========================================
// Buffer Class - default copy constructor
// =========================================

class Buffer {
public:

	typedef enum : uint32_t {
		TYPE_INVALID,
		TYPE_LINEAR,
		TYPE_GRAPHIC,
	} type_t;

	Buffer() = default;

	// Members in a member initializer list are always initialized
	// in the order in which they are defined inside the class
	// (not in the order they are defined in the member initializer list).
	explicit Buffer(uint32_t len, uint32_t size, type_t type) :
		m_len(len),
		m_size(size),
		m_type(type)
		{}

	Buffer &operator=(Buffer &buf)
	{
		m_len = buf.m_len;
		m_size = buf.m_size;
		m_type = buf.m_type;
		return *this;
	}

	uint32_t getSize() { return m_size; };
	uint32_t getLength() { return m_len; };
	type_t getType() const { return m_type; };
	void printBufInfo();

private:
	uint32_t m_len{0};
	uint32_t m_size{0};
	type_t m_type{TYPE_INVALID};
};

void Buffer::printBufInfo()
{
	printf("New buffer ==============\n");
	printf("Buffer length = %u\n", this->getLength());
	printf("Buffer size = %u\n", this->getSize());
	printf("Buffer type = %s\n",
		(this->getType() == TYPE_INVALID) ? "INVALID" :
		this->getType() == TYPE_GRAPHIC ? "GRAPHIC" : "LINEAR");
}

// =========================================
// CBuffer Class - default copy constructor
// =========================================

class CBuffer {
public:

	typedef enum : uint32_t {
		TYPE_INVALID,
		TYPE_LINEAR,
		TYPE_GRAPHIC,
	} type_t;

	CBuffer() = default;
	CBuffer(uint32_t len, uint32_t size, type_t type) :
		m_len(len),
		m_size(size),
		m_type(type)
		{}

	// Copy constructor - Pass const lvalue reference
	CBuffer(CBuffer &cbuf) :
		m_len(cbuf.m_len),
		m_size(cbuf.m_size),
		m_type(cbuf.m_type)
		{
			printf("CBuffer - Copy constructor\n");
		}


	uint32_t getSize() { return m_size; };
	uint32_t getLength() { return m_len; };
	type_t getType() const { return m_type; };
	void printBufInfo();

private:
	Buffer &operator=(Buffer &buf) = delete;
	uint32_t m_len{0};
	uint32_t m_size{0};
	type_t m_type{TYPE_INVALID};
};

void CBuffer::printBufInfo()
{
	printf("New buffer ==============\n");
	printf("Buffer length = %u\n", this->getLength());
	printf("Buffer size = %u\n", this->getSize());
	printf("Buffer type = %s\n",
		(this->getType() == TYPE_INVALID) ? "INVALID" :
		this->getType() == TYPE_GRAPHIC ? "GRAPHIC" : "LINEAR");
}

// =========================================
// GBuffer Class - private copy constructor
// =========================================

class GBuffer {
public:

	typedef enum : uint32_t {
		TYPE_INVALID,
		TYPE_LINEAR,
		TYPE_GRAPHIC,
	} type_t;

	GBuffer() = delete;
	explicit GBuffer(uint32_t len, uint32_t size, type_t type) :
		m_len(len),
		m_size(size),
		m_type(type)
		{}


	uint32_t getSize() { return m_size; };
	uint32_t getLength() { return m_len; };
	type_t getType() const { return m_type; };
	void printBufInfo();

private:
	// Copy constructor
	GBuffer(GBuffer &gbuf);
	GBuffer &operator=(GBuffer &buf) = delete;
	uint32_t m_len{0};
	uint32_t m_size{0};
	type_t m_type{TYPE_INVALID};
};

void GBuffer::printBufInfo()
{
	printf("New buffer ==============\n");
	printf("Buffer length = %u\n", this->getLength());
	printf("Buffer size = %u\n", this->getSize());
	printf("Buffer type = %s\n",
		(this->getType() == TYPE_INVALID) ? "INVALID" :
		this->getType() == TYPE_GRAPHIC ? "GRAPHIC" : "LINEAR");
}

// =========================================
// Tests
// =========================================


int main()
{
	Buffer b1(5, 10, Buffer::TYPE_LINEAR);
	b1.printBufInfo();

	// Default copy constructor
	Buffer b2(b1);
	b2.printBufInfo();

	// copy constructor
	CBuffer c1(20, 20, CBuffer::TYPE_GRAPHIC);
	CBuffer c2(c1);
	c2.printBufInfo();

	// cannot call private copy constructor
	GBuffer g1(20, 40, GBuffer::TYPE_GRAPHIC);
//	GBuffer g2(g1);

	// copy elision
	Buffer b3(Buffer{20, 50, Buffer::TYPE_GRAPHIC});
	b3.printBufInfo();

	// Default constructor is deleted, invalid call
	// GBuffer g3;

	// Copy assignment
	Buffer b4 = b3;
	b4.printBufInfo();

	// Copy assignment - default assignment
	CBuffer c3 = c2;
	c3.printBufInfo();

	// Copy initialization
	CBuffer c4 = {10, 25, CBuffer::TYPE_GRAPHIC};
	c4.printBufInfo();

	// Copy assignment is now allowed
	GBuffer g2(2, 4, GBuffer::TYPE_GRAPHIC);
	//g2 = g1;

	return 0;
}

