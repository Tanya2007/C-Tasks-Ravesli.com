#include <iostream>

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
	std::cout << "Enter the time in minutes: ";
	int minutes(inputValue());
	
	std::cout << minutes << " minutes = ";
	
	int hours = minutes / 60;
	int days = hours / 24;
	minutes -= hours * 60;
	hours -= days * 24;
	
	std::cout << days << " days " << hours << " hours " << minutes << " minutes\n";
	
	return 0;
}