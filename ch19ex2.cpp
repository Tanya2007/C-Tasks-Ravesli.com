#include <iostream>
#include <random>
#include <algorithm>

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if (std::cin.fail() || value < 0)
		{
			std::cin.clear();
			std::cin.ignore(32767,'\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return value;
		}

		std::cout << "\nInvalid input, try again: ";
	}
}

int main()
{
	auto myGenerate =
	    []() -> int
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(-10000, 10000);
		return distrib(rnd);
	};
	
	std::cout << "Enter an integer: ";
	int N(inputValue());
	
	int *arr = new int[N];
	
	for(int i{}; i < N; ++i)
	{
		arr[i] = myGenerate();
		std::cout << arr[i] << " ";
	}
	
	std::cout << "\n";
	
	auto it = std::max_element(arr, arr + N);
	
	std::cout << "Max element: " << *it << ", by index: " << it - arr << "\n";
	
	delete [] arr;
	
	return 0;
}

