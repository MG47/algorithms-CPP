/*
* Program to study 'mutable'
*/

#include <cstdio>
#include <cstdint>

struct GraphicBuffer {
	GraphicBuffer(size_t len)
	{
		mId = GraphicBuffer::sCount++;
		mSize = len;
	}

	static uint32_t sCount;
	uint32_t mId = 0;
	mutable size_t mSize;
	void *mMem = nullptr;
};

uint32_t GraphicBuffer::sCount = 0;

void print_buf_info(const GraphicBuffer *gbuf)
{
	if (!gbuf)
		return;

	// Access
	printf("======\n");
	printf("gbuf ID = %u\n", gbuf->mId);
	printf("gbuf len = %lu\n", gbuf->mSize);
	printf("======\n");
}

void update_buf_len(const GraphicBuffer *gbuf, size_t len)
{
	// Cannot modify member of a const object
	//gbuf.mId = 2;

	// Mutable members can be modified
	gbuf->mSize = len;
}

int main()
{
	/* C++ - mutable */
	const GraphicBuffer gbuf(1024);

	update_buf_len(&gbuf, 4096);

	print_buf_info(&gbuf);

	return 0;
}

