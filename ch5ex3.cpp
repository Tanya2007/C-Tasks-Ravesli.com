#include <iostream>
#include <chrono>
#include <thread>

#if defined (_WIN32)
#include <Windows.h>

void beep()
{
	Beep(500, 800);
}
//for other operating systems, 
//you need to write your own function "beep()"
#endif

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
	std::cout << "Enter the time in seconds: ";
	int seconds(inputValue());
	
	std::this_thread::sleep_for(std::chrono::seconds(seconds));
	beep();
	
	return 0;
}