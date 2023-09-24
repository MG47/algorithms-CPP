/*
* Program to study std::thread
*/

#include <cstdio>
#include <thread>

void print_thread_details(int seq)
{
	// Without synchronization, threads can execute in any order
	printf("Thread id %d, seq %d\n", std::this_thread::get_id(), seq);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	printf("Thread %d exiting\n", seq);
}

void test_joinable_threads()
{

	std::thread threadlist[4];

	for (int i = 0; i < 4; i++)
		threadlist[i] = std::thread(print_thread_details, i);

	printf("Main thread... waiting for others to join...\n");
	for (int i = 0; i < 4; i++)
		threadlist[i].join();

	printf("Main thread... all threads joined, exiting\n");

}

void test_detachable_threads()
{

	std::thread threadlist[4];

	for (int i = 0; i < 4; i++) {
		threadlist[i] = std::thread(print_thread_details, i);
		threadlist[i].detach();
	}

	printf("Main thread... all threads detached, exiting\n");
}

int main()
{
	/* C++ - std::thread */

	test_joinable_threads();

	test_detachable_threads();

	std::this_thread::sleep_for(std::chrono::seconds(5));

	return 0;
}

