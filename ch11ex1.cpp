#include <iostream>
#include <regex>
#include <string>
#include <iomanip>

double inputValue()
{
	std::regex double_regex("\\d+\\.?\\d{0,3}");
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
	std::cout << "Enter the weight in pounds: ";
	double pounds(inputValue());
	
	std::cout << pounds << " pounds = " << std::fixed << std::setprecision(3) << pounds * 0.4536 << " kg\n";
	
	return 0;
}