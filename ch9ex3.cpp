#include <iostream>
#include <vector>
#include <random>

///////////////////////////////////////////////////////////////
int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if (std::cin.fail() || (!(value >= 1 && value <= 5)))
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
////////////////////////////////////////////////////////////////////////////////////
const std::vector<int>& setComputer(const std::vector<std::vector<int> > &setNumbers)
{
	auto myGenerate =
	[]() -> int
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(0, 4);
		return distrib(rnd);
	};

	int index = myGenerate();

	return setNumbers[static_cast<std::size_t>(index)];
}
/////////////////////////////////////////////////////////////////////////////////////
int main()
{
	const std::vector<std::vector<int> > setNumbers
	{
		{6, 7, 8},
		{7, 8, 9},
		{6, 9, 10},
		{6, 9, 8},
		{7, 6, 10}
	};

	const auto set_computer{setComputer(setNumbers)};

	std::cout << "Choose an option from a set of numbers (1 - 5):\
	\n1. {6, 7, 8}\
	\n2. {7, 8, 9}\
	\n3. {6, 9, 10}\
	\n4. {6, 9, 8}\
	\n5. {7, 6, 10}\
	\nYour choice: ";
	int choose{inputValue()};
	
	const std::vector<int> &set_player = setNumbers[static_cast<std::size_t>(choose) - 1];

	auto functionSumm =
	[](const std::vector<int> &vec) -> int
	{
		int summ(0);
		for(const auto &elem : vec)
		{
			summ += elem;
		}
		return summ;
	};
	
	int summPlayer = functionSumm(set_player);
	int summComputer = functionSumm(set_computer);
	
	if(summPlayer == summComputer)
		std::cout << "Draw!\n";
	else if(summPlayer < summComputer)
		std::cout << "You've lost...\n";
	else
		std::cout << "Hooray! You've won!)\n";
		
	return 0;
}