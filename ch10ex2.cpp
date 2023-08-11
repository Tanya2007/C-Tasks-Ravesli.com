#include <iostream>
#include <regex>
#include <string>

std::string inputValue()
{
	std::regex double_regex("^\\d{6}$");
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
	
	return value;
}

int main()
{
	std::cout << "Enter a six-digit number: ";
	std::string value(inputValue());
	
	int summFirst(0);
	int summLast(0);
	int count(1);
	char ch[2];
	
	for(std::size_t i{}; i < value.size(); ++i)
	{
		ch[0] = value.c_str()[i];
		ch[1] = '\0';
		
		if(count <=3)
			summFirst += atoi(ch);
		else
			summLast += atoi(ch);
			
		++count;
	}
	
	if(summFirst == summLast)
		std::cout << "The number " << value << " is a lucky one )\n";
	else
		std::cout << "The number " << value << " is not a lucky one (...\n";
	
	return 0;
}