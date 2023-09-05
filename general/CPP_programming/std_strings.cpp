/*
* Program to study std::strings
*/

#include <cstdio>
#include <string>

void print_string_view(std::string_view str)
{
	std::cout << str;
}


void test_string_view()
{
	std::string_view str{"Hel"};
	print_string_view(str);

	std::string str2 {str};
	print_string_view(str2);

	std::string_view str3(str);
	str3 = "World";
	print_string_view(str3);

}

void print_string(std::string *str)
{
	std::cout << *str;
}

void test_strings()
{
	std::string str1, str2, str3;

	str1 = "Hello";
	str2 = " World";

	printf("str1 = %s\n", str1.c_str());
	printf("str2 = %s\n", str2.c_str());
	printf("str1+str2 = %s\n", (str1+str2).c_str());
	printf("str1 max capacity = %u\n", (unsigned int)str1.capacity());
	printf("str3 is %s\n", str3.empty() ? "Empty" : "Non-empty");

	str3 = str1;
	printf("str3 is %s\n", str3.empty() ? "Empty" : "Non-empty");
	str3[0] = 'J';
	printf("str3 = %s\n", str3.c_str());
	printf("str1 = %s\n", str1.c_str());

	int len = str1.length(), i = 0;
	while (i < len) {
		printf("str[%d]:%c\n", i, str1.at(i));
		i++;
	}

	printf("str1 front = %c\n", str1.front());
	printf("str1 addr = %p\n", str1.data());

	// const iterator
	std::string::const_iterator cit;
	for (cit = str1.cbegin(); cit != str1.cend(); ++cit) {
		//now allowed
		//*it = 'd';
		printf("%c\n", *cit);
	}

	// iterator
	std::string::iterator it;
	for (it = str1.begin(); it != str1.end(); ++it) {
		*it = 'd';
		printf("%c\n", *it);
	}

	str1.clear();
	printf("str1 = %s\n", str1.c_str());

	str1 = "World";
	printf("str1 has %s at location %u\n", "rl", (unsigned int)str1.find("rl"));

	std::string str4;

	char charstr[6];
	str1.copy(charstr, sizeof charstr);
	printf("charstr: %s\n", charstr);

	str4 = str1;
	str4.at(3) = 'z';
	printf("str4: %s\n", str4.c_str());

	printf("compare: %s\n", !str4.compare(str1) ?
		"str1 == str4" : str4.compare(str1) > 0 ?
		"str4 > str1" : "str1 > str4" );

	print_str(&str4);
}

int main()
{
	/* C++ - std::strings, std::string_view */

	test_strings();

	test_string_view();

	return 0;
}

