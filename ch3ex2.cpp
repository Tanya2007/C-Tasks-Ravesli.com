#include <iostream>

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
	std::cout << "Enter the number of summable numbers: ";
	int count{inputValue()};
	unsigned long long summ{0};
	
	for(int i{}, n{2}; i < count; ++i, n += 2)
	{
		summ += static_cast<unsigned long long>(n);
	}
	
	std::cout << "The sum of the first " << count << " positive even integers is equal to: " << summ << "\n";
	
	return 0;
}