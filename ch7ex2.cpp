#include <iostream>
#include <regex>
#include <string>

int main()
{
	std::regex int_regex("^-?\\d+$");
	std::string value{"0"};
	
	std::cout << "Enter the line: ";
	std::getline(std::cin, value);
	
	if(std::regex_match(value, int_regex))
	{
		std::cout << value << " is an integer.\n";
	}
	else
	{
		std::cout << value << " is not an integer.\n";
	}
	
	return 0;
}