/*
* Program to study std::set and std::unordered_set
*/

#include <cstdio>
#include <string>
#include <unordered_set>
#include <set>

/* =========== std::set =========== */
void print_set(const std::set<int> *nums)
{

	printf("--printing set--\n");
	printf("size of set = %lu\n", nums->size());
	printf("Max size of set = %lu\n", nums->max_size());

	for (std::set<int>::const_iterator it = nums->cbegin();
		it != nums->cend(); ++it)
		printf("%d\n", *it);
}

void test_set()
{
	std::set<int> nums, copynums;

	nums.insert(10);
	nums.insert(30);
	nums.insert(20);
	nums.insert(20);
	nums.erase(4);
	nums.erase(10);
	nums.emplace(120);
	nums.emplace(220);

	print_set(&nums);

	copynums = nums;

	print_set(&copynums);

	nums.clear();
	print_set(&nums);

	std::set<int>::iterator it, it2;

	it = copynums.begin();
	std::advance(it, 1);

	it2 = it;
	std::advance(it2, 2);

	copynums.erase(it, it2);
	print_set(&copynums);

	int a = 30;
	if (copynums.find(a) == copynums.end()) {
		printf("could not find %d in set\n", a);
	}

	//TODO declare set
	std::set<char> charset = {'a', 'b', 'd'};
	printf("size of charset = %lu\n", charset.size());


	// find unique characters in a word, sorted alphabetically
	std::string word = "helloworld";
	std::set<char> uniq;

	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
		uniq.insert((*it));

	printf("Unique characters in %s: %lu\n", word.c_str(), uniq.size());

	for (std::set<char>::const_iterator it = uniq.cbegin();
		it != uniq.cend(); ++it)
		printf("%c\n", *it);
}

/* =========== std::unordered_set =========== */


void test_unordered_set()
{
	// find unique characters in a word
	std::string word = "helloworld";
	std::unordered_set<char> uniq;

	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
		uniq.insert((*it));

	printf("Unique characters in %s: %lu\n", word.c_str(), uniq.size());

	for (std::unordered_set<char>::const_iterator it = uniq.cbegin();
		it != uniq.cend(); ++it)
		printf("%c\n", *it);
}

int main()
{

	test_unordered_set();

	test_set();

	return 0;
}

