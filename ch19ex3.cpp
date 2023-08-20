#include <iostream>
#include <random>

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
	int count{};
	
	auto myGenerate =
	    []() -> int
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(0, 9);
		return distrib(rnd);
	};
	
	int a, b, c;
	for(int i{}; i < 10; ++i)
	{
		a = myGenerate();
		b = myGenerate();
		
		std::cout << a << " * " << b << " = ";
		c = inputValue();
		
		if(a * b == c)
		{
			std::cout << "Right!\n";
			++count;
		}
		else
		{
			std::cout << "Wrong answer...\n";
		}
	}
	
	switch(count)
	{
		case 10:
			std::cout << "You know the multiplication table perfectly well!\n";
			break;
			
		case 9:
		case 8:
			std::cout << "You know the multiplication table well!\n";
			break;
			
		case 7:
		case 6:
			std::cout << "You know the multiplication table satisfactorily.\n";
			break;
			
		default:
			std::cout << "You don't know the multiplication table well...(\n";
			break;
	}
	
	return 0;
}