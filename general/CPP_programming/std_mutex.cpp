/*
* Program to study std::mutex, std::lock_guard
*/

#include <cstdio>
#include <thread>
#include <mutex>

std::mutex seq_mutex;

void print_thread_details(int seq)
{
	std::lock_guard<std::mutex> lock(seq_mutex);
	printf("Thread %d\n", seq);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	printf("Thread %d exiting\n", seq);
}

int main()
{
	/* C++ - std::mutex */

	std::thread threadlist[4];

	for (int i = 0; i < 4; i++)
		threadlist[i] = std::thread(print_thread_details, i);

	printf("Main thread... waiting for others to join...\n");

	for (int i = 0; i < 4; i++)
		threadlist[i].join();

	printf("Main thread... all threads joined, exiting\n");

	return 0;
}

