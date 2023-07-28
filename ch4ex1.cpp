#include <iostream>
#include <iomanip>

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if ( std::cin.fail() || value < 0)
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
	constexpr double ONE_VERST{1.0668};
	
	std::cout << "Enter the distance in versts: ";
	int versts{inputValue()};
	
	std::cout << versts << " versts = ";
	std::cout << std::fixed << std::setprecision(2) << versts * ONE_VERST << " km\n";
	
	return 0;
}