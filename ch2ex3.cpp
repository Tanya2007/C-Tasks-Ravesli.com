#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>

int inputValue()
{
    int value{};
    while(true)
    {
        std::cin >> value;
    
        if (std::cin.fail() || (!(value >= 100 && value <= 999))) 
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
	auto myGenerate =
	[]() -> int
	{  
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(100, 999);
		return distrib(rnd);
	};
	
	int digit = myGenerate();
	
	std::string digitStr = std::to_string(digit);
	
	std::cout << "The computer made a three-digit number. You have to guess it.\n";
	std::cout << "After the next number, you will be informed how many digits are guessed";
	std::cout << " and how many of them are in their places.\n\n";
	
	int numberPlayer;
	std::string numberPlayerStr;
	
	do
	{
		std::cout << "Your version: ";
		numberPlayer = inputValue();
		numberPlayerStr = std::to_string(numberPlayer);
		std::vector<char> numbPlayerStrVec;
		
		for(std::size_t i = 0; i < numberPlayerStr.size(); ++i)
		{
			numbPlayerStrVec.push_back(numberPlayerStr.c_str()[i]);
		}
	
		int guessed_right(0);
		int in_places(0);
		
		for(std::size_t i = 0; i < numberPlayerStr.size(); ++i)
		{
			if(digitStr[i] == numberPlayerStr[i])
				++in_places;
			
			auto iterVec = std::find(numbPlayerStrVec.begin(), numbPlayerStrVec.end(), digitStr.c_str()[i]);
			
			if(iterVec != numbPlayerStrVec.end())
			{
				++guessed_right;
				numbPlayerStrVec.erase(iterVec);
			}	
		}
		
		std::cout << "Guessed right: " << guessed_right;
		std::cout << ". In their places: " << in_places << ".\n\n";
				
	}while(digit != numberPlayer);
	
	std::cout << "***You guessed the number " << digit << "!***\n";
	
	return 0;
}