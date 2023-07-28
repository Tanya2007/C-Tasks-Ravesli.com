#include <iostream>
#include <regex>
#include <string>
#include <iomanip>
#include <float.h>

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
	std::cout << "Enter the number of sequence numbers: ";
	int count(inputValue());
	
	int i(1);
	double summ(0);
	double ch(0);
	double min(DBL_MAX);
	double max(DBL_MIN);
	
	std::cout << "Enter the sequence: ";
	
	while(i <= count)
	{
		ch = inputValue();
		
		if(ch < min)
			min = ch;
			
		if(ch > max)
			max = ch;
		
		summ += ch;
		++i;
	}
	
	std::cout << "Arithmetic mean: ";
	std::cout << std::fixed << std::setprecision(2) << summ / count << "\n";
	
	std::cout << "Minimum number: " << min << "\n";
	std::cout << "Maximum number: " << max << "\n";
	
	return 0;
}