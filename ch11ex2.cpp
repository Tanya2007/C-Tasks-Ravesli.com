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

int main()
{
	std::cout << "Enter your monthly scholarship: ";
	double rubles(inputValue());

	double expenses;
	while(true)
	{
		std::cout << "Enter the living expenses for the first month: ";
		expenses = inputValue();

		if(std::round(expenses * 100) <= std::round (rubles * 100))
		{
			std::cout << "Expenses are less than or equal to income. No extra money is needed.\n";
			return 0;
		}
		
		break;
	}
	
	double summ_expenses(expenses);
	for(int i = 1; i < 10; ++i)
	{
		expenses *= 1.03;
		summ_expenses += expenses;
	}
	
	std::cout << "To stay for the next 10 months, you will need to get ";
	std::cout << std::fixed << std::setprecision(2) << summ_expenses - rubles * 10 << " rubles, in addition to your scholarship.\n"; 

	return 0;
}