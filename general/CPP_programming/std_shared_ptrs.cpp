/*
* Program to study std::shared_ptr
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

void print_buf_info(std::shared_ptr<GraphicBuffer> gbuf)
{
	if (!gbuf)
		return;

	// Access
	printf("======\n");
	printf("gbuf len = %lu\n", gbuf ? gbuf->mSize : 0);
	gbuf->isMapped();
	gbuf.get()->isMapped();
	(*gbuf).isMapped();
	printf("Use count = %lu\n", gbuf.use_count());
	printf("======\n");
}

void test_shared_ptr()
{
	/* ================================================================ */
	int *numptr = new int(10);
	std::shared_ptr<int> numshptr(numptr);
	int *numptr2 = numshptr.get();
	printf("int val through numptr2 = %d\n", numptr2 ? *numptr2 : 0);
	numshptr.reset(new int(15));
	printf("int val through numptr2 = %d\n", numptr2 ? *numptr2 : 0);
	printf("int val through numshptr = %d\n", numshptr ? *numshptr : 0);


	/* ================================================================ */

	std::shared_ptr<GraphicBuffer> gbuf1(new GraphicBuffer(1024));

	{
		std::shared_ptr<GraphicBuffer> gbuf2 = gbuf1;

	}
	printf("Destroyed gbuf2\n");
	print_buf_info(gbuf1);


	struct GraphicBuffer *gbuf3ptr = new GraphicBuffer(4096	);
	std::shared_ptr<GraphicBuffer> gbuf3(gbuf3ptr);
	{
		// gbuf3 and gbuf4 are not aware of each other
		// This leads to double free
		// std::shared_ptr<GraphicBuffer> gbuf4(gbuf3ptr);
	}

	std::shared_ptr<GraphicBuffer> gbuf5 = std::make_shared<GraphicBuffer>(8192);
	gbuf5.reset(new GraphicBuffer(16 * 1024));

	print_buf_info(gbuf5);
}

int main()
{
	/* C++ - std::shared_ptr */
	test_shared_ptr();

	return 0;
}

