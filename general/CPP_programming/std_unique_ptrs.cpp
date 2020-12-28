/*
* Program to study std::unique_ptr
*/

#include <cstdio>
#include <memory>
#include <vector>

struct GraphicBuffer {
	GraphicBuffer(size_t len) : mSize(len)
	{
		printf("GraphicBuffer construction\n");
		mId = sCount++;
		printf("GraphicBuffer ID = %u\n", mId);
	}

	~GraphicBuffer() {
		printf("GraphicBuffer destructor\n");
		printf("GraphicBuffer ID = %u\n", mId);
	}

	void isMapped() {
		printf("is %s\n", mMem ? "mapped" : "not mapped");
	}

	static uint32_t sCount;
	uint32_t mId = 0;
	size_t mSize;
	void *mMem = nullptr;
};

uint32_t GraphicBuffer::sCount = 0;

void print_buf_info(std::unique_ptr<GraphicBuffer> gbuf)
{
	if (!gbuf)
		return;

	// Access
	printf("======\n");
	printf("gbuf len = %lu\n", gbuf ? gbuf->mSize : 0);
	gbuf->isMapped();
	gbuf.get()->isMapped();
	(*gbuf).isMapped();
	printf("======\n");
}


void test_unique_ptr()
{
	std::unique_ptr<GraphicBuffer> gbuf1(new GraphicBuffer(2048));
	std::unique_ptr<GraphicBuffer> gbuf2(new GraphicBuffer(128));
	std::unique_ptr<GraphicBuffer> gbuf3(new GraphicBuffer(512));
	std::unique_ptr<GraphicBuffer> gbuf4(new GraphicBuffer(64));

	//nullptr
	std::unique_ptr<GraphicBuffer> gbuf5;

	// Not allowed, copy construction is disabled
	// gbuf5 = gbuf1;

	printf("gbuf5 %s\n", gbuf5 ? "holds a resource" :
		" does not hold a resource");
	gbuf5 = std::move(gbuf1);
	printf("gbuf5 %s\n", gbuf5 ? "holds a resource" :
		" does not hold a resource");

	// Access
	printf("======");
	printf("gbuf5 len = %lu\n", gbuf5 ? gbuf5->mSize : 0);
	gbuf5->isMapped();
	gbuf5.get()->isMapped();
	(*gbuf5).isMapped();
	printf("======");

	std::vector<std::unique_ptr<GraphicBuffer>> bufv;
	// Not allowed
	//bufv.push_back(gbuf1);
	bufv.push_back(std::move(gbuf2));
	bufv.push_back(std::move(gbuf3));
	bufv.push_back(std::move(gbuf4));

	std::vector<std::unique_ptr<GraphicBuffer>>::iterator it;
	for (it = bufv.begin(); it != bufv.end(); ++it) {
		(*it)->isMapped();
	}

	// cannot access gbuf2
	// gbuf2->isMapped();
	gbuf2 = std::move(bufv[0]);
	gbuf2->isMapped();


	//release
	struct GraphicBuffer* gptr = gbuf2.release();
	if (gptr)
		delete gptr;

	// reset
	gbuf5.reset(new GraphicBuffer(2048));


//	auto gbuf6 = std::make_unique<GraphicBuffer>(8192);
//	print_buf_info(std::move(gbuf6));


	/* ============= */
	std::unique_ptr<int []> arr(new int[10]);


	for (int i = 0; i < 10; i++) {
		arr[i] = i;
		printf("i = %d\n", i);
	}



}

int main()
{
	/* C++ - std::unique_ptr */
	test_unique_ptr();

	return 0;
}

