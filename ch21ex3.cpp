#include <iostream>
#include <string>
#include <random>

int main()
{
	std::cout << "Select the password difficulty level (1 - easy, 2 - medium, 3 - difficult): ";
	int level;
	
	while(true)
	{
		std::cin >> level;
		if (std::cin.fail() || level < 1 || level > 3)
		{
			std::cin.clear();
			std::cin.ignore(32767,'\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			break;
		}

		std::cout << "\nInvalid input, try again: ";
	}
	
	std::string password;
	
	auto passwordGenerate =
	    [&password](int count, int start, int end)
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(start, end);
		for(int i = 0; i < count; ++i)
		{
			password += static_cast<char>(distrib(rnd));
		}
	};
	
	if(level == 1)
	{
		passwordGenerate(10, 97, 122);
		std::cout << password;
	}
	else if(level == 2)
	{
		passwordGenerate(15, 65, 122);
		std::cout << password;
	}
	else
	{
		passwordGenerate(20, 33, 126);
		std::cout << password;
	}
	
	return 0;
}