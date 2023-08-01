#include <iostream>
#include <regex>
#include <string>
#include <iomanip>

double inputValue()
{
	std::regex double_regex("\\d+\\.?\\d{0,2}");
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

int main()
{
	std::cout << "Enter the price for 1 kg of product: ";
	double price(inputValue());
	
	double price100gr = price / 10;
	
	std::cout << std::fixed;
	std::cout << "Weigth \t\t\t" << "Cost\n";
	std::cout << "(gram) \t\t\t" << "($)\n";
	
	int i{100};
	while(i <= 1000)
	{
		std::cout << i << "\t\t\t" << std::setprecision(2) << price100gr * i / 100 << "\n";
		i += 100;
	}
	
	return 0;
}