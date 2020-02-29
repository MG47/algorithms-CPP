/*
* Program to study enums
*/

#include <cstdio>
#include <cstdint>

/*
* C-style enums with type specifiers
**/
enum car_type : uint64_t {
        LUXURY_SPORTS,
        SEDAN,
        SUV,
};

/*
* Enum classes
*/
enum class Gear : uint32_t {
	/* Manual */
	FIRST 	= 1,
	SECOND 	= 2,
	THIRD 	= 3,
	FOURTH 	= 4,
	FIFTH 	= 5,
	SIXTH 	= 6,
	SEVENTH = 7,
	EIGHTH 	= 8,

	/* Auto */
	NEUTRAL = 0x100,
	REVERSE = 0x101,
	PARK 	= 0x102,
	DRIVE 	= 0x103,
	LOW 	= 0x104,
};

struct car {
        enum car_type type;
        enum Gear current_gear;
}__attribute((packed));

static inline enum Gear current_gear(struct car c)
{
	return c.current_gear;
}

void initialize_car_data(struct car *c)
{
	if (!c)
		return;
	c->type = SEDAN;
	c->current_gear = Gear::NEUTRAL;
}

void change_gear(struct car *c, enum Gear new_gear)
{
	if (!c)
		return;

	c->current_gear = new_gear;
}

int main()
{

	struct car c;
	initialize_car_data(&c);

	printf("sizeof strcut car = %lu\n", sizeof(c));
	printf("car : current gear = 0x%x\n", current_gear(c));
	printf("car : type = %lu\n", c.type);

	change_gear(&c, Gear::REVERSE);
	printf("car : current gear = 0x%x\n", current_gear(c));

        return 0;
}

