#include <iostream>
#include <vector>
#include <algorithm>

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
	std::cout << "Enter a sequence of positive integers (0 - for exit): ";
	
	int temp(0);
	std::vector<int> v_int;
	
	while((temp = inputValue()))
	{
		std::cout << "\n";
		v_int.push_back(temp);
	}
	
	auto min_elem = std::min_element(v_int.begin(), v_int.end());
	
	std::cout << "Minimum sequence element: " << *min_elem << "\n";
	
	return 0;
}