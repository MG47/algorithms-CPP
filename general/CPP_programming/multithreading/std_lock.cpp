/*
* Program to study C++ locks
*/

#include <cstdio>
#include <thread>
#include <mutex>

struct Counter {
    int mCount = 1;
    std::mutex mCounterLock;
};

void increment_counter(int seq, struct Counter &counter)
{
	// Without synchronization, threads can execute in any order
#if 0
    int readVal = counter.mCount;
    printf("Thread id %d, seq %d read the counter: %d\n",
            std::this_thread::get_id(), seq, readVal);
    counter.mCount += readVal;
    printf("Thread id %d, seq %d incremented counter to (%d + %d) = %d\n",
            std::this_thread::get_id(), seq, readVal, readVal, counter.mCount);
#else
    {
        std::lock_guard<std::mutex> lock(counter.mCounterLock);
        int readVal = counter.mCount;
        printf("Thread id %d, seq %d read the counter: %d\n",
                std::this_thread::get_id(), seq, readVal);
        counter.mCount += readVal;
        printf("Thread id %d, seq %d incremented counter to (%d + %d) = %d\n",
                std::this_thread::get_id(), seq, readVal, readVal, counter.mCount);
    }
#endif

}

void test_threads_locks()
{

	std::thread threadlist[4];
    struct Counter counter;

	for (int i = 0; i < 4; i++)
		threadlist[i] = std::thread(increment_counter, i, std::ref(counter));

	printf("Main thread... waiting for others to join...\n");
	for (int i = 0; i < 4; i++)
		threadlist[i].join();

	printf("Main thread... all threads joined, counter = %d\n", counter.mCount);
}

int main()
{
	/* C++ - std::thread */

	test_threads_locks();

	std::this_thread::sleep_for(std::chrono::seconds(5));

	return 0;
}

