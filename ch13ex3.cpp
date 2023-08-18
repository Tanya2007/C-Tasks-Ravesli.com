#include <iostream>
#include <fstream>
#include <random>

int main()
{
	auto myGenerate =
	    []() -> int
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(0, 1);
		return distrib(rnd);
	};
	
	std::ofstream outf("SomeText.txt", std::ios::trunc); 
	int heads{0};
	int tails{0};
	
	if(outf)
	{
		for(int i{}; i < 100; ++i)
		{
			if(myGenerate() == 0)
			{
				outf << "heads\n";
				++heads;
			}
			else
			{
				outf << "tails\n";
				++tails;
			}
		}
		
		std::cout << "heads = " << heads << ", tails = " << tails << "\n";
		outf << "heads = " << heads << ", tails = " << tails << "\n";
	}
	else
	{
		std::cout << "Could not open the file SomeText.txt\n";
	}
	
	return 0;
}