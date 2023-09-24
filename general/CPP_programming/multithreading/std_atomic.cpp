/*
* Program to study std::atomic TODO
*/

#include <cstdio>
#include <iostream>
#include <thread>
#include <atomic>

/* Singleton class */
class Registry {
	public:
		static void init()
		{
			if (mIsInitialized_bool == false) {
				mInitCnt++;
				printf("mInitCnt = %u\n", mInitCnt);
				mIsInitialized_bool = true;
			}
		}

		static void atomic_init()
		{
			bool init = false;
			if (mIsInitialized.compare_exchange_strong(init, true) == true) {
				mInitCnt++;
				printf("mInitCnt = %u\n", mInitCnt);
				mIsInitialized.store(true);
			}
		}

	private:
		Registry();
		static uint32_t mInitCnt;
		static bool mIsInitialized_bool;
		static std::atomic<bool> mIsInitialized;
};

uint32_t Registry::mInitCnt = 0;
bool Registry::mIsInitialized_bool(false);
std::atomic<bool> Registry::mIsInitialized(false);

int main()
{
	/* C++ - std::atomic */
	std::thread threadlist[4];

//#define NON_ATOMIC
#ifdef NON_ATOMIC
	// non-atomic initialization
	for (int i = 0; i < 4; i++)
		threadlist[i] = std::thread(Registry::init);
#else
	// atomic initialization
	for (int i = 0; i < 4; i++)
		threadlist[i] = std::thread(Registry::atomic_init);
#endif

	printf("Main thread... waiting for others to join...\n");

	for (int i = 0; i < 4; i++)
		threadlist[i].join();

	printf("Main thread... all threads joined, exiting\n");

	return 0;
}

