/*
* Program to study std::map and std::unordered_map
*/

#include <cstdio>
#include <unordered_map>
#include <map>

struct buf {
public:
	buf(bool linear)
	: mIsLinear(false),
	  mMap(nullptr)
	{
		mIsLinear = linear;
	};
	bool mIsLinear;
private:
	void *mMap;
};

/* =========== std::map =========== */
void print_map(const std::map<std::string, int> &map)
{
	printf("==================\n");
	printf("Map size = %lu\n", map.size());

	std::map<std::string, int>::const_iterator it;
	for (it = map.cbegin(); it != map.cend(); ++it)
		printf("%s : %d\n", it->first.c_str(), it->second);
	printf("==================\n");
}

void print_map(const std::map<unsigned int, struct buf *> &bmap)
{
	printf("==================\n");
	printf("Map size = %lu\n", bmap.size());

	std::map<unsigned int, struct buf *>::const_iterator it;
	for (it = bmap.cbegin(); it != bmap.cend(); ++it)
		printf("%u : %s\n", it->first,
			it->second->mIsLinear ? "Linear" : "Non-Linear");
	printf("==================\n");
}

void test_map()
{
	std::map<std::string, int> tbl;

	tbl["Pen"] = 10;
	tbl["Pencil"] = 5;
	tbl["Notepad"] = 15;
	tbl["Book"] = 2;

	print_map(tbl);

	printf("Value of %s = %d\n", "Pen", tbl["Pen"]);
	printf("Value of %s = %d\n", "Pen", tbl["Pen"]);

	tbl.insert({"Eraser", 3});
	tbl.insert(std::make_pair("Ruler", 5));
	print_map(tbl);


	std::map<unsigned int, struct buf *> bufmap;

	// do not care about 'delete'
	bufmap.emplace(2, new buf(false));
	bufmap.emplace(1024, new buf(true));
	bufmap.emplace(8, new buf(false));
	bufmap.emplace(16, new buf(false));
	bufmap.emplace(256, new buf(true));
	bufmap.emplace(4, new buf(false));
	bufmap.emplace(128, new buf(true));

	print_map(bufmap);
}

/* =========== std::unordered_map =========== */
void print_umap(const std::unordered_map<std::string, int> &umap)
{
	printf("Table size = %lu\n", umap.size());

	std::unordered_map<std::string, int>::const_iterator it;
	for (it = umap.cbegin(); it != umap.cend(); ++it)
		printf("%s : %d\n", it->first.c_str(), it->second);
	printf("==================\n");
}

void test_unordered_map()
{
	std::unordered_map<std::string, int> tbl;

	tbl["Pen"] = 10;
	tbl["Pencil"] = 5;
	tbl["Notepad"] = 15;
	tbl["Book"] = 15;

	print_umap(tbl);

	printf("Value of %s = %d\n", "Pen", tbl["Pen"]);
	printf("Value of %s = %d\n", "Pen", tbl["Pen"]);

	tbl.insert({"Eraser", 3});
	tbl.insert(std::make_pair("Ruler", 5));
	print_umap(tbl);

	std::unordered_map<std::string, int>::iterator it = tbl.begin();
	std::advance(it, 2);
	it = tbl.erase(it);
	printf("iterator is at '%s = %d'\n", (*it).first.c_str(), (*it).second);
	print_umap(tbl);


	tbl.clear();
	print_umap(tbl);

	std::unordered_map<std::string, int> nums = {
		{"one", 1,},
		{"twenty", 20},
		{"two thirty-three", 233},
		{"seven", 7},
	};

	print_umap(nums);

	// count letters in a word
	std::unordered_map<char, unsigned int> freq;
	std::string word = "helloworld";

	for (std::string::iterator it = word.begin(); it != word.end(); ++it)
		freq[*it]++;

	for (auto it = freq.cbegin();
		it != freq.cend(); ++it) {
		printf("char :'%c' freq = %u\n", (*it).first, (*it).second);
	}
}

int main()
{

	test_unordered_map();

	test_map();

	return 0;
}

