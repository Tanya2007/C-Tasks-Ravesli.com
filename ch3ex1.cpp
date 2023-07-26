#include <iostream>
#include <regex>
#include <string>
#include <iomanip>

double inputValueDistanceKilometers()
{
    int value{};
    while(true)
    {
        std::cin >> value;
    
        if (std::cin.fail()) 
        {
            std::cin.clear(); 
            std::cin.ignore(32767,'\n'); 
        }
        else
        {
            std::cin.ignore(32767, '\n');
            return value / 1000.0;
        }
        
        std::cout << "\nInvalid input, try again: ";
    }
}

double inputValueTimeInHours()
{
	std::regex double_regex("(\\d+)\\.([0-5][0-9])");
	std::smatch sm;
	std::string value{"0"};
	double timeHours;
	
	while(true)
	{
		std::cin >> value;
		
		if (std::regex_search(value, sm, double_regex))
		{
			double minutes = atof(sm[1].str().c_str());
			double seconds = atof(sm[2].str().c_str());
			
			timeHours = (minutes * 60 + seconds) / 3600;
			break;
		}
		
		std::cout << "\nInvalid input, try again: ";
	}
		
	return timeHours;
}

int main()
{
	std::cout << "Enter the distance length (in meters): ";
	double distanceKilometers(inputValueDistanceKilometers()); 
	
	std::cout << "Enter the time (minutes.seconds): ";
	double timeHours(inputValueTimeInHours());
	
	std::cout << "You ran with speed: ";
	std::cout << std::fixed << std::setprecision(2) << distanceKilometers / timeHours;
	std::cout << " km/h\n";
	
	return 0;
}