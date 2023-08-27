#include <iostream>
#include <random>

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if (std::cin.fail() || value < 1 || value > 10)
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
	int count{100};
	int player(0);
	int computer(0);
	
	auto myGenerate =
	    []() -> int
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(1, 10);
		return distrib(rnd);
	};
	
	while(count > 0)
	{
		std::cout << "Number of player matches: ";
		player = inputValue();
		count -= player;
		if(count <= 0)
		{
			std::cout << "You've lost\n";
			break;
		}
		
		computer = myGenerate();
		if(count < computer)
			computer = count;
		std::cout << "The computer took " << computer << " matches.\n";
		count -= computer;
		
		if(count <= 0)
		{
			std::cout << "Victory!!!\n";
			break;
		}
	}

	return 0;
}