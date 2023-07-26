#include <iostream>
#include <regex>
#include <string>
#include <iomanip>
#include <cmath>

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

double Amount_including_discount(double amount, double discount)
{
	return amount - (amount * discount / 100);
}

int main()
{
	constexpr int rounding_multiplier{100};
	
	std::cout << "Enter the purchase amount $: ";
	double amount{inputValue()};
	std::cout << "\n";
	
	int amount_rounding = std::round(amount * rounding_multiplier);
	
	if(amount_rounding > 50000 && amount_rounding <= 100000)
	{
		std::cout << "You are given a discount of 3%\n";
		std::cout << "Amount including discount: ";
		std::cout << std::fixed << std::setprecision(2) << Amount_including_discount(amount, 3) << "$\n";
	}
	else if(amount_rounding > 100000)
	{
		std::cout << "You are given a discount of 5%\n";
		std::cout << "Amount including discount: ";
		std::cout << std::fixed << std::setprecision(2) << Amount_including_discount(amount, 5) << "$\n";
	}
	else
	{
		std::cout << "The purchase amount is less than 500.01$\n";
		std::cout << "You are not given a discount\n";
		std::cout << "Purchase amount: ";
		std::cout << std::fixed << std::setprecision(2) << amount << "$\n";
	}
	
	return 0;
}