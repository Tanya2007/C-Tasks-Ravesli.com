#include <iostream>
#include <vector>

int main()
{
	std::vector<int> daysMonth{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	std::cout << "Enter the date (date month year) in numbers: ";
	int d, m, y;

	while(true)
	{
		std::cin >> d >> m >> y;
		if ( std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767,'\n');
			
			std::cout << "\nInvalid input, try again: ";
			continue;
		}
		
		if(y % 4 == 0)
			daysMonth[1] = 29;
			
		if(m >= 1 && m <= 12)
		{
			if(d >= 1 && d <= daysMonth[static_cast<std::size_t>(m) - 1])
				break;
		}
		
		std::cout << "\nInvalid input, try again: ";
	}
	
	if(d == daysMonth[static_cast<std::size_t>(m) - 1])
	{
		d = 1;
		if(m == 12)
		{
			m = 1;
			++y;
		}	
		else
			++m;
	}
	else
		++d;

	std::cout << "Tomorrow: " << (d > 9 ? "" : "0") << d << "." << (m > 9 ? "" : "0") << m << "." << y << "\n";
	
	return 0;
}