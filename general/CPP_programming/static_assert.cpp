/*
* Program to study static_assert
*/

#define LIB_VERSION 0.1

int main()
{
	static_assert(sizeof(int) == 4, "sizeof(int) must be 4 bytes!!");
	static_assert(LIB_VERSION >= 0.2, "LIB_VERSION must be at least 0.2");

	return 0;
}

