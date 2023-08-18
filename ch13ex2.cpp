#include <iostream>
#include <set>

int main()
{
	std::size_t count(0);
	std::set<std::set<int> > set_lucky;
	
	int first_summ{13}; 
	
	for(int i{49}; i < 1000; ++i)
	{
		std::set<int> temp;
		bool isLucky{false};
		
		if(i < 100)
		{
			int a{i / 10};
			int b{i % 10};
			if(a + b == first_summ)
			{
				isLucky = true;
				temp.insert({0, a, b});
			}		
		}
		else
		{
			int a{i / 100};
			int b{i % 100};
			int c{b / 10};
			int d{b % 10};
			if(a + c + d == first_summ)
			{
				isLucky = true;
				temp.insert({a, c, d});
			}		
		}
		
		if(isLucky)
			set_lucky.insert(temp);
	}
	
	for(auto iter1 = set_lucky.begin(); iter1 != set_lucky.end(); ++iter1)
	{
		std::size_t set_size1 = (*iter1).size();
		
		if(set_size1 == 3)
			set_size1 = 6;
		else if(set_size1 == 2)
			set_size1 = 3;
			
		for(auto iter2 = set_lucky.begin(); iter2 != set_lucky.end(); ++iter2)
		{
			std::size_t set_size2 = (*iter2).size();
			
			if(set_size2 == 3)
				set_size2 = 6;
			else if(set_size2 == 2)
				set_size2 = 3;
				
			count += set_size1 * set_size2;
		}
	}
	
	std::cout << "The number of lucky tickets with numbers from 000000 to 999999\n";
	std::cout << "with the sum of the first three digits equal to " << first_summ << ": " << count << "\n";
	
	return 0;
}