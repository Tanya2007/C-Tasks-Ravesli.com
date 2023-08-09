#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>

/////////////////////////////////////////////////////////
double inputValue()
{
	std::regex double_regex("\\-?\\d+\\.?\\d{0,2}");
	std::string value{"0"};
	while(true)
	{
		std::cin >> value;
		
		if(std::regex_match(value, double_regex))
		{
			break;
		}
		
		std::cout << "\nInvalid input, try again: ";
	}
	
	return atof(value.c_str());
}
///////////////////////////////////////////////////////////
int main()
{
	std::vector<double> arr;
	
	char ch;
	double number;
	
	do
	{
		std::cout << "Enter the number: ";
		number = inputValue();
		
		arr.push_back(number);
		
		std::cout << "Continue typing? (y/n): ";
		std::cin >> ch;
		
	}while (ch == 'y');
	
	std::cout << "Enter the number to be checked: ";
	double checked(inputValue());
	
	auto iter = std::find(arr.begin(), arr.end(), checked);
	
	if(iter != arr.end())
		std::cout << "The number " << checked << " is in the array.\n";
	else
		std::cout << "The number " << checked << " is not in the array.\n";
	
	return 0;
}