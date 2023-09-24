/*
* Program to study classes - PART I
*/

#include <cstdint>
#include <cstdio>


/*
* PART I:
* Test Basic classes, access specifiers
* constructor/destructors
* const members, static members,
* friend functions/classes,
* anonymous objects, class nesting
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
	void setLength(Buffer &b, uint32_t);
	type_t getType() const;
	void printBufInfo();
	static uint32_t get_destruct_count();
	void reset();
	friend void reset(Buffer *buf);
	friend class BufferFiller;

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

private:
	static uint32_t m_destruct_count;
	uint32_t m_len{0};
	uint32_t m_size{0};
	type_t m_type{TYPE_INVALID};
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

void Buffer::setLength(Buffer &b, uint32_t len)
{
	b.m_len = len;
}

Buffer::type_t Buffer::getType() const
{
	return m_type;
}


void Buffer::reset()
{
	this->m_len = 0;
	this->m_size = 0;
	this->m_type = Buffer::TYPE_INVALID;
}

// =========================================

void Buffer::printBufInfo()
{
	printf("New buffer ==============\n");
	printf("Buffer length = %u\n", this->getLength());
	printf("Buffer size = %u\n", this->getSize());
	printf("Buffer type = %s\n",
		(this->getType() == TYPE_INVALID) ? "INVALID" :
		this->getType() == TYPE_GRAPHIC ? "GRAPHIC" : "LINEAR");
	printf("buffer Class Destruct count %u\n", get_destruct_count());

}

void printBufType(const Buffer *b)
{
	printf("New buffer ==============\n");

// Not allowed - can only call other const functions
//	printf("Buffer length = %u\n", b->getLength());
//	printf("Buffer size = %u\n", b->getSize());

// Call to const functions are allowed
	printf("Buffer type = %s\n",
		(b->getType() == Buffer::TYPE_INVALID) ? "INVALID" :
		b->getType() == Buffer::TYPE_GRAPHIC ? "GRAPHIC" : "LINEAR");
	printf("buffer Class Destruct count %u\n", Buffer::get_destruct_count());
}

void reset(Buffer *buf)
{
	// Friend function - can access private data of buf
	buf->m_len = 0;
	buf->m_size = 0;
	buf->m_type = Buffer::TYPE_INVALID;
}

// =========================================
// BufferFiller Class
// =========================================

class BufferFiller {
public:
	void fillBuffer(Buffer buf)
	{
		// friend class - can access private members
		buf.m_len = 10;
		buf.m_size = 10;
	}
};

// =========================================
// Tests
// =========================================

void test_class_with_ptr(Buffer *b)
{
	b->printBufInfo();
}

void test_class_with_ref(Buffer &b)
{
	b.printBufInfo();
}

void test_class()
{

	Buffer b;
	b.printBufInfo();

	test_class_with_ref(b);

	Buffer c(10, 2, Buffer::TYPE_LINEAR);
	c.printBufInfo();
	c.reset();
	c.printBufInfo();

	// Access Levels work on per-class basis.
	// Any object of the same class can access private members
	// of other objects of the same class
	c.setLength(b, 10);
	b.printBufInfo();

	Buffer *buf;
	buf = new Buffer(100);
	test_class_with_ptr(buf);
	printBufType(buf);
	reset(buf);
	buf->printBufInfo();
	delete buf;

	// const obj
	const Buffer cbuf(1, 2, Buffer::TYPE_GRAPHIC);
	printBufType(buf);

	// Anonymous Buffer object passed to friend class
	BufferFiller bf;
	bf.fillBuffer(Buffer());

	// Nested class - BufferPrinter
	Buffer::BufferPrinter bp;
	bp.print(c);
}

int main()
{
	test_class();
	return 0;
}

