/*
* Program to study std::weak_ptr
*/

#include <cstdio>
#include <memory>

struct GraphicBuffer {
	GraphicBuffer(size_t len) : mSize(len)
	{
		printf("GraphicBuffer construction\n");
		mId = sCount++;
		printf("GraphicBuffer ID = %u\n", mId);
	}

	~GraphicBuffer()
	{
		printf("GraphicBuffer destructor\n");
		printf("GraphicBuffer ID = %u\n", mId);
	}

	void isMapped()
	{
		printf("is %s\n", mMem ? "mapped" : "not mapped");
	}

	static uint32_t sCount;
	uint32_t mId = 0;
	size_t mSize;
	void *mMem = nullptr;
};

uint32_t GraphicBuffer::sCount = 0;

void print_buf_info(std::weak_ptr<GraphicBuffer> gbuf)
{

}

void test_weak_ptr()
{
	/* ================================================================ */
	int *num = new int;
	*num = 10;
	std::weak_ptr<int> numwptr;

	{
		std::shared_ptr<int> numshptr(num);
		numwptr = numshptr;
		{
			std::shared_ptr<int> numshptr2 = numshptr;
			printf("num count = %lu\n", numwptr.use_count());
			if (auto tempshptr = numwptr.lock()) {
				printf("num = %d\n", *tempshptr);
			}

		}
		printf("num count = %lu\n", numwptr.use_count());
		if (auto tempshptr = numwptr.lock()) {
			printf("num = %d\n", *tempshptr);
		}
	}

	printf("num count = %lu\n", numwptr.use_count());
	if (auto tempshptr = numwptr.lock()) {
		printf("num = %d\n", *tempshptr);
	} else {
		printf("num does not exist\n");
	}

	/* ================================================================ */

}

int main()
{
	/* C++ - std::weak_ptr */
	test_weak_ptr();

	return 0;
}

