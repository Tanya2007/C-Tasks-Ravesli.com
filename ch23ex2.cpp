#include <iostream>
#include <set>
#include <random>

void fillSet(std::set<int> &set_fill)
{
	auto myGenerate =
	    []() -> int
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(-100, 100);
		return distrib(rnd);
	};

	for(int i{}; i < 100; ++i)
	{
		set_fill.insert(myGenerate());
	}
}

void printSet(std::set<int> &set_fill)
{
	for(auto iter = set_fill.begin(); iter != set_fill.end(); ++iter)
	{
		std::cout << *iter << " ";
	}

	std::cout << "\n";
}

int main()
{
	std::set<int> arr1;
	std::set<int> arr2;
	std::set<int> result;

	fillSet(arr1);
	fillSet(arr2);

	printSet(arr1);
	printSet(arr2);

	result = arr1;
	for(auto iter = arr2.begin(); iter != arr2.end(); ++iter)
	{
		result.insert(*iter);
	}
	
	printSet(result);

	return 0;
}