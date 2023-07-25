#include <iostream>
#include <regex>
#include <string>
#include <iomanip>

double inputValue()
{
	std::regex double_regex("\\d+\\.?\\d*");
	std::string value{"0"};
	while(true)
	{
		std::cin >> value;
		
		if(std::regex_match(value, double_regex))
		{
			break;
		}
		
		std::cout << "\nInvalid input, try again: ";
	}
	
	return atof(value.c_str());
}

class CostTrip
{
	protected:
		double m_distance;
		double m_gasoline_consumption; //per 100 km
		double m_price_liter_gasoline;

	public:
		CostTrip(double d = 0, double g = 0, double p = 0)
			: m_distance{d}, m_gasoline_consumption{g}, m_price_liter_gasoline{p}
		{
		}

		virtual double calculateCostTrip() const
		{
			double cost_trip = m_distance * m_gasoline_consumption / 100 
				* m_price_liter_gasoline * 2;
				
			return cost_trip;
		}

		virtual std::istream& output(std::istream& in)
		{
			std::cout << "Distance to the cottage (km): ";
			m_distance = inputValue();
			std::cout << "\n";

			std::cout << "Gasoline consumption (liters per 100 km of mileage): ";
			m_gasoline_consumption = inputValue();
			std::cout << "\n";

			std::cout << "The price of a liter of gasoline ($): ";
			m_price_liter_gasoline = inputValue();
			std::cout << "\n";

			return in;
		}

		friend std::istream& operator>>(std::istream &in, CostTrip &obj)
		{
			return obj.output(in);
		}

		virtual ~CostTrip()
		{
		}
};

int main()
{
	CostTrip costTrip;
	std::cin >> costTrip;
	std::cout << "A trip to the country and back will cost in: ";
	std::cout << std::fixed << std::setprecision(2) << costTrip.calculateCostTrip() << "$\n";

	return 0;
}
