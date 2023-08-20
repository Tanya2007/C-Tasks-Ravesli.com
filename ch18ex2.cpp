#include <iostream>
#include <vector>
#include <map>

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
	std::cout << "Enter an array of integers: ";
	std::vector<int> arrInteger;
	char ch{'y'};
	
	do
	{
		arrInteger.push_back(inputValue());
		std::cout << "Continue? (y/n): ";
		std::cin >> ch;	
	}while(ch == 'y');
	
	std::map<int, int> intDouble;
	
	for(auto elem : arrInteger)
	{
		++intDouble[elem];
	}
	
	std::vector<int> arrNotDouble;
	
	for(auto elem : arrInteger)		//deleting all elements that occur more than twice
	{
		if(intDouble[elem] <= 2)
			arrNotDouble.push_back(elem);
	}
	
	for(auto elem : arrNotDouble)
	{
		std::cout << elem << " ";
	}
	
	std::cout << "\n";
	
	arrNotDouble.clear();
	
	for(auto elem : arrInteger)		//if there are more than two identical 
									//numbers in the sequence, then two such 
									//numbers remain, the remaining duplicates are deleted
	{
		if(intDouble[elem] > 2)
		{
			intDouble[elem] = 2;
		}
		
		if(intDouble[elem])
		{
			--intDouble[elem];
			arrNotDouble.push_back(elem);
		}
	}
	
	for(auto elem : arrNotDouble)
	{
		std::cout << elem << " ";
	}
	
	std::cout << "\n";
	
	return 0;
}