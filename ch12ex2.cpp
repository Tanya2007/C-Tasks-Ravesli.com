#include <iostream>
#include <vector>
#include <string_view>

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if (std::cin.fail() || (!(value >= 1 && value <= 365)))
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
	std::vector<std::string_view> daysWeek{"Monday", "Tuesday", "Wednesday",
	                        	"Thursday", "Friday", "Saturday", "Sunday"};

	std::cout << "Enter the day of the year (1 - 365): ";
	int dayYear(inputValue());

	int wholeWeeks = (dayYear - 1) / 7;
	
	std::size_t index = static_cast<std::size_t>(dayYear - wholeWeeks * 7 - 1);
	
	std::cout << "The " << dayYear << "th day of the year is " << daysWeek[index] << "\n";

	return 0;
}