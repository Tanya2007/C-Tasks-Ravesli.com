#include <iostream>
#include <string>
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
	std::string arrHex{"0123456789ABCDEF"};
	std::cout << "Enter a positive decimal integer: ";
	int dec_pl{inputValue()};
	
	std::string hex_pl{};
	while(dec_pl)
	{
		int rem = dec_pl%16;
		dec_pl = (dec_pl - rem)/16;
		hex_pl += arrHex[static_cast<std::size_t>(rem)];
	}
	
	hex_pl += "xO";
	std::reverse(hex_pl.begin(), hex_pl.end());
	
	std::cout << hex_pl << "\n";
	
	return 0;
}