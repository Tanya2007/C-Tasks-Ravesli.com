#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
	std::ifstream happy_in("ch24ex2_happy_numbers.txt");
	std::ifstream prime_in("ch24ex2_prime_numbers.txt");
	std::vector<int> happy_vec;
	std::vector<int> prime_vec;

	int temp;
	if(happy_in)
	{
		while(happy_in >> temp)
		{
			happy_vec.push_back(temp);
		}
	}

	if(prime_in)
	{
		while(prime_in >> temp)
		{
			auto iter = std::find(happy_vec.begin(), happy_vec.end(), temp);
			if(iter == happy_vec.end())
			{
				prime_vec.push_back(temp);
			}
			else
			{
				happy_vec.erase(iter);
			}
		}
	}

	happy_in.close();
	prime_in.close();

	std::ofstream happy_out("ch24ex2_happy_numbers_result.txt");
	std::ofstream prime_out("ch24ex2_prime_numbers_result.txt");

	if(happy_out)
	{
		for(std::size_t i{}; i < happy_vec.size(); ++i)
		{
			happy_out << happy_vec[i] << "\n";
		}
	}

	if(prime_out)
	{
		for(std::size_t i{}; i < prime_vec.size(); ++i)
		{
			prime_out << prime_vec[i] << "\n";
		}
	}

	happy_out.close();
	prime_out.close();

	return 0;
}