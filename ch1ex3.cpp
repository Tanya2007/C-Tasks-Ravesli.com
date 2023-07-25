#include <iostream>
#include <vector>
#include <string>

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if ( std::cin.fail() || (!(value >= 1 && value <= 12)) )
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
	std::vector<std::string> seasons{"spring", "summer", "autumn", "winter"};

	std::cout << "Enter the month number (number from 1 to 12): ";
	int number = inputValue();

	std::cout << "\n";

	switch(number)
	{
		case 3:
		case 4:
		case 5:
			std::cout << seasons[0] << "\n";
			break;

		case 6:
		case 7:
		case 8:
			std::cout << seasons[1] << "\n";
			break;

		case 9:
		case 10:
		case 11:
			std::cout << seasons[2] << "\n";
			break;

		case 1:
		case 2:
		case 12:
			std::cout << seasons[3] << "\n";
			break;
	}

	return 0;
}