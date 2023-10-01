/*
* Program to study std::queue
*/

#include <cstdio>
#include <queue>
#include <cstdint>

// =========================================
// Buffer Class
// =========================================

class Buffer {
public:

	enum BufferType : uint32_t {
		TYPE_INVALID,
		TYPE_LINEAR,
		TYPE_GRAPHIC,
	};

	Buffer() = default;
	explicit Buffer(uint32_t len, uint32_t size, BufferType type) :
		mLen(len),
		mSize(size),
		mType(type)
		{}

	uint32_t getSize() { return mSize; };
	uint32_t getLength() { return mLen; };
	BufferType getType() const { return mType; };
	void printBufInfo();

private:
	uint32_t mLen{0};
	uint32_t mSize{0};
	BufferType mType{TYPE_INVALID};
};

// =========================================

void Buffer::printBufInfo()
{
	printf("============== buffer ==============\n");
	printf("Buffer length = %u\n", this->getLength());
	printf("Buffer size = %u\n", this->getSize());
	printf("Buffer type = %s\n",
		(this->getType() == TYPE_INVALID) ? "INVALID" :
		this->getType() == TYPE_GRAPHIC ? "GRAPHIC" : "LINEAR");
}

void print_queue_info(std::queue<Buffer> &bufqueue)
{
	printf("======= Queue ========\n");
	printf("Queue Size = %d\n", bufqueue.size());
	printf("Queue Empty ? = %s\n", bufqueue.empty() ? "YES" : "NO");
	printf("Queue Front (bufsize)= %d\n", bufqueue.front().getSize());
	printf("Queue Back (bufsize)= %d\n", bufqueue.back().getSize());
}

void print_queue_info(std::queue<int> &numqueue)
{
	printf("======= Queue ========\n");
	printf("Queue Size = %d\n", numqueue.size());
	printf("Queue Empty ? = %s\n", numqueue.empty() ? "YES" : "NO");
	printf("Queue Front = %d\n", numqueue.front());
	printf("Queue Back = %d\n", numqueue.back());

}

void test_queue()
{
	/* ========================== numqueue ========================== */
	std::queue<int> q1;
	q1.push(5);
	q1.push(10);
	q1.push(15);
	q1.push(20);

	print_queue_info(q1);
}

void test_bufqueue()
{
	/* ========================== queue ========================== */
	std::queue<Buffer> bufq;

	Buffer b1(1, 100, Buffer::TYPE_GRAPHIC);
	bufq.push(b1);
	bufq.emplace(10, 10, Buffer::TYPE_LINEAR);
	bufq.emplace(5, 10, Buffer::TYPE_LINEAR);

	print_queue_info(bufq);

	Buffer b2 = bufq.front();
	b2.printBufInfo();
	Buffer b3 = bufq.back();
	b3.printBufInfo();

	bufq.pop();
	bufq.pop();
	print_queue_info(bufq);

	auto bufq2 = bufq;
	bufq2.emplace(50, 50, Buffer::TYPE_LINEAR);
	print_queue_info(bufq2);
}

int main()
{
	/* C++ - std::queue */

	test_queue();
	test_bufqueue();

	return 0;
}

