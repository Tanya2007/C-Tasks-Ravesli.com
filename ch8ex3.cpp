#include <iostream>

///////////////////////////////////////////////////////////////
int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if (std::cin.fail() || (!(value >= 0 && value <= 5)))
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

/////////////////////////////////////////////////////////////////////////////

int main()
{
	std::cout << "Average diploma score: ";
	int score(inputValue());

	std::cout << "Work experience: ";
	int experience(inputValue());

	int passingScore(0);

	if(experience == 0)
	{
		passingScore = score;
	}
	else if(experience < 2)
	{
		passingScore = score * 13;
	}
	else if(experience <= 5)
	{
		passingScore = score * 16;
	}

	if(passingScore < 45)
	{
		std::cout << "your rating is " << passingScore;
		std::cout << ", you are not accepted to the master's program.\n";
	}
	else
	{
		std::cout << "Congratulations! Your passing score is " << passingScore;
		std::cout << ", you are accepted to the Master's program.\n";
	}
	
	return 0;
}