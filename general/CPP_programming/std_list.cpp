/*
* Program to study std::list
*/

#include <cstdio>
#include <list>
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

void print_list(std::list<Buffer> *buflist)
{
	if (buflist == nullptr)
		return;

	printf("<---------printing buflist----------->\n");
	for (std::list<Buffer>::iterator it = buflist->begin(); it != buflist->end(); ++it) {
		(*it).printBufInfo();
	}
}

void print_list(std::list<int> &numlist)
{
	printf("--printing list--\n");
	printf("size of list %u\n", (uint32_t)numlist.size());
	printf("is empty ?: %s \n", numlist.empty() ? "YES" : "NO");
	printf("--at front : %d--\n", numlist.front());

	int i = 0;
	for (std::list<int>::iterator it = numlist.begin(); it != numlist.end(); ++it) {
		printf("%d:%d\n", i++, *it);
	}
}

void test_list()
{
	/* ========================== numlist ========================== */

	std::list<int> numlist;
	std::list<int>::iterator lit;


	numlist.push_front(2);
	numlist.push_front(1);
	lit = numlist.begin();
	std::advance(lit, 2);
	numlist.insert(lit, 3);
	std::advance(lit, 1);
	numlist.insert(lit, 4);

	numlist.push_back(5);
	numlist.push_back(6);
	numlist.push_back(7);
	numlist.push_back(8);

	print_list(numlist);

	numlist.reverse();
	numlist.sort();
	print_list(numlist);

	printf("sizeof list: %u\n", (uint32_t)numlist.size());
	numlist.pop_front();
	printf("sizeof list: %u\n", (uint32_t)numlist.size());

	printf("num at beginning: %d end: %d list: \n", *numlist.begin(), *numlist.rbegin());


	numlist.resize(2);
	numlist.erase(numlist.begin());
	print_list(numlist);
	numlist.clear();
	print_list(numlist);

}

void test_buflist()
{
	/* ========================== buflist ========================== */
	std::list<Buffer> buflist;

	Buffer b(0, 100, Buffer::TYPE_GRAPHIC);
	buflist.push_back(b);
	print_list(&buflist);

	buflist.erase(buflist.begin());
	print_list(&buflist);

	buflist.emplace_back(10, 10, Buffer::TYPE_LINEAR);
	buflist.emplace_back(5, 10, Buffer::TYPE_LINEAR);
	print_list(&buflist);
}

int main()
{
	/* C++ - std::list */

	test_list();
	test_buflist();

	return 0;
}

