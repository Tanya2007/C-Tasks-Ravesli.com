#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

constexpr int VALUE{5};

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if ( std::cin.fail() || (value < 1 || value > 5))
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

struct Student
{
	std::string m_FIO{};
	int m_year_study{};
	int m_rating[VALUE] {};
};

int main()
{
	Student arrStudent[VALUE];

	double averageTotal{0.0};

	for(auto &elem : arrStudent)
	{
		std::cout << "Enter the FIO: ";
		std::getline(std::cin, elem.m_FIO);

		std::cout << "Enter the year of study: ";
		elem.m_year_study = inputValue();

		std::cout << "Enter the student's five grades: ";
		for(std::size_t i{}; i < VALUE; ++i)
		{
			elem.m_rating[i] = inputValue();
			averageTotal += elem.m_rating[i];
		}
	}

	averageTotal /= VALUE * VALUE;
	
	std::cout << "\nOverall average score: ";
	std::cout << std::fixed << std::setprecision(2) << averageTotal << "\n";

	std::sort(arrStudent, arrStudent + VALUE,
	    [](const auto &obj1, const auto &obj2)
	{
		return obj1.m_FIO < obj2.m_FIO;
	});

	auto Average =
	    [](int *rating) -> double
	{
		double av{0.0};
		for(std::size_t i{}; i < VALUE; ++i)
		{
			av += rating[i];
		}

		return av / VALUE;
	};

	bool better{false};

	for(auto &elem : arrStudent)
	{
		double avTemp{Average(elem.m_rating)};
		
		if(std::round(avTemp * 100) > std::round(averageTotal * 100))
		{
			std::cout << "FIO: " << elem.m_FIO << "\n";
			std::cout << "Year of study: " << elem.m_year_study << "\n";
			std::cout << "Average student performance: ";
			std::cout << std::fixed << std::setprecision(2) << avTemp << "\n";
			better = true;
		}
	}

	if(!better)
	{
		std::cout << "There are no students whose average score exceeds the total average score.\n";
	}

	return 0;
}