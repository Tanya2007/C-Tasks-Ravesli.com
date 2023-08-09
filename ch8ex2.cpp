#include <iostream>
#include <string>
#include <algorithm>

/////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////

int main()
{
	std::cout << "Enter the number: ";
	int number(inputValue());
	
	std::string str{std::to_string(number)};
	std::string str_reverse{str};
	std::reverse(str_reverse.begin(), str_reverse.end());
	
	if(str == str_reverse)
		std::cout << str << " is a palindrome.\n";
	else
		std::cout << str << " is not a palindrome.\n";
		
	return 0;
}