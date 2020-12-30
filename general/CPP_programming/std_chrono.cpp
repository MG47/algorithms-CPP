/*
* Program to study std::chrono, chrono_literals
*/

#include <cstdio>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void print_literals()
{
	std::chrono::microseconds usecs = 30us;
	std::chrono::hours hours = 1h;
	std::chrono::minutes mins = 25min;
	std::chrono::seconds secs = 32s;

	printf("usecs = %llu\n", usecs.count());
	printf("elapsed time = %02d:%02d:%02llu\n", hours.count(), mins.count(), secs.count());
}

void print_duration()
{
	// std::chrono::time_point<std::chrono::high_resolution_clock>
	auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	auto stop = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli> dr_mcrs= stop - start;
	printf("duration slept for = %fms\n", dr_mcrs.count());

}

int main()
{

	print_duration();

	print_literals();

	return 0;
}

