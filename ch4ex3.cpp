#include <iostream>
#include <vector>
#include <algorithm>

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if (std::cin.fail())
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
	std::cout << "Enter the number of elements of the first array: ";
	int count(inputValue());
	
	std::cout << "Enter the elements of the first array:\n";
	
	std::vector<int> firstArray;
	while (count > 0)
	{
		int elem(inputValue());
		firstArray.push_back(elem);
		--count;
	}
	
	std::cout << "Enter the number of elements of the second array: ";
	count = inputValue();
	
	std::cout << "Enter the elements of the second array:\n";
	
	std::vector<int> secondArray;
	while (count > 0)
	{
		int elem(inputValue());
		secondArray.push_back(elem);
		--count;
	}
	
	std::sort(firstArray.begin(), firstArray.end());
	std::sort(secondArray.begin(), secondArray.end());
	
	std::vector<int> arrayResult(firstArray.size() + secondArray.size());
	std::merge(firstArray.begin(), firstArray.end(), secondArray.begin(), secondArray.end(), arrayResult.begin());
	
	std::cout << "Array-result: ";
	for(const auto &elem : arrayResult)
	{
		std::cout << elem << " ";
	} 
	
	std::cout << "\n";
	
	return 0;
}