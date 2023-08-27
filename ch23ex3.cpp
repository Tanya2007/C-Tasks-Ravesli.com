#include <iostream>
#include <conio.h>

char inputValue()
{
	char ch;
	while(true)
	{
		std::cin >> ch;
		if(ch == '>' || ch == '<' || ch == '=')
			break;
	}
	
	return ch;
}

int main()
{
	std::cout << "Guess a number from 0 to 1000. Press any key when you're ready.\n";
	char ch = getch();
	
	int start = 0;
	int end = 1000;
	int count = 0;
	
	while(true)
	{
		++count;
		std::cout << "Your number: " << (end + start) / 2 << "\n";
		std::cout << " '>', '<' or '=' :  ";
		ch = inputValue();
		
		if(ch == '=')
		{
			std::cout << "The number is guessed for " << count << " attempts.\n";
			break;
		}
		else if(ch == '>')
		{
			start = (end + start) / 2;
		}
		else if(ch == '<')
		{
			end = (end + start) / 2;
		}	
		
		if(end - start == 1)
		{
			end += 1;
		}
	}
	
	return 0;
}