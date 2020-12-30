/*
* Program to study std::condition_variable
*/

#include <cstdio>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>

std::mutex cvm;
std::condition_variable cv;
std::mutex listlock;
std::list<int> intlist;
bool pending;

void produce()
{
	std::lock_guard<std::mutex> lk(cvm);
	intlist.push_back(1);
	intlist.push_back(4);
	intlist.push_back(5);
	intlist.push_back(6);
	pending = true;
	printf("producer thread: signaling all..\n");
	cv.notify_all();
	printf("producer thread: exiting..\n");
}

void consume(int id)
{
	printf("thread %d waiting ...!\n", id);
	std::unique_lock<std::mutex> lk(cvm);
	cv.wait(lk, []{return pending; });
	std::lock_guard<std::mutex> lock(listlock);
	printf("thread %d list back: %d\n", id, intlist.back());
	intlist.pop_back();
}

int main()
{

	pending = false;
	std::thread threadlist[4];

	for (int i = 0; i < 3; i++)
		threadlist[i] = std::thread(consume, i);

	threadlist[3] = std::thread(produce);

	for (int i = 0; i < 4; i++)
		threadlist[i].join();

	return 0;
}

