/*
* Program to study casts
*/
#include <cstdio>
#include <cstdint>

void test_static_cast()
{
	int i = 2410;
	char c;

	// Implicit casting
	c = i;
	printf("value of c = %d\n", c);

	// C-style casts
	c = (char)i;
	printf("value of c = %d\n", c);

	c = static_cast<char>(i);
	printf("value of c = %d\n", c);

}

void test_const_cast()
{
	int test = 455;
	const int fixed = 500;
	const int *test_ptr = &test;
	const int *fixed_ptr;

	printf("test value = %d\n", *test_ptr);

	// Need to const-cast to remove const-ness of test_ptr
	// *test_ptr = 200;
	*const_cast<int *>(test_ptr) = 200;
	printf("test value = %d\n", *test_ptr);

	fixed_ptr = &fixed;
	printf("fixed value = %d\n", *fixed_ptr);

	/* This compiles, but should not const-cast a ptr pointing to a const variable */
	//*const_cast<int *>(fixed_ptr) = 200;
	//printf("fixed value = %d\n", *fixed_ptr);

}

void test_dynamic_cast()
{

}



/*==================== reinterpret_cast =================== */

struct buffer {
	unsigned int len;
	void *va;

};

struct vbuffer {
	uint32_t length;
	void *map;
};

void test_reinterpret_cast()
{
	int i = 2410;
	int *iptr = &i;
	uint8_t c;
	uint8_t *cptr = &c;

	cptr = reinterpret_cast<uint8_t *>(iptr);
	printf("value of c = %c(char) %d(int)\n", *cptr, *cptr);
}

/*==================== static_pointer_cast =================== */

void test_static_pointer_cast()
{

}

void test_const_pointer_cast()
{

}

int main()
{

	test_static_cast();

	test_const_cast();

	test_dynamic_cast();

	test_reinterpret_cast();

	test_static_pointer_cast();

	test_const_pointer_cast();

	return 0;
}

