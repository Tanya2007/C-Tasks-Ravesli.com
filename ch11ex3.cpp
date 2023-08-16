#include <iostream>

int inputValue(std::istream &in)
{
	int value{};
	while(true)
	{
		in >> value;

		if (in.fail() || (!(value >= 0 && value <= 9)))
		{
			in.clear();
			in.ignore(32767,'\n');
		}
		else
		{
			in.ignore(32767, '\n');
			return value;
		}

		std::cout << "\nInvalid input, try again: ";
	}
}

class ThreeDigitCode
{
		int m_first;
		int m_second;
		int m_third;

	public:
		ThreeDigitCode(int a = 0, int b = 0, int c = 0)
			: m_first(a), m_second(b), m_third(c)
		{
		}

		friend std::ostream& operator << (std::ostream &out, const ThreeDigitCode &obj);
		friend std::istream& operator >> (std::istream &in, ThreeDigitCode &obj);
		friend bool operator == (const ThreeDigitCode &obj1, const ThreeDigitCode &obj2);
		ThreeDigitCode& operator++();
};

std::ostream& operator << (std::ostream &out, const ThreeDigitCode &obj)
{
	out << obj.m_first << obj.m_second << obj.m_third;

	return out;
}

std::istream& operator >> (std::istream &in, ThreeDigitCode &obj)
{
	obj.m_first = inputValue(in);
	obj.m_second = inputValue(in);
	obj.m_third = inputValue(in);

	return in;
}

bool operator == (const ThreeDigitCode &obj1, const ThreeDigitCode &obj2)
{
	return obj1.m_first == obj2.m_first && obj1.m_second == obj2.m_second && obj1.m_third == obj2.m_third;
}

ThreeDigitCode& ThreeDigitCode::operator++()
{
	++m_third;
	
	if(m_third == 10)
	{
		m_third = 0;
		++m_second;
	}
	
	if(m_second == 10)
	{
		m_second = 0;
		++m_first;
	}
	
	return *this;
}

int main()
{
	ThreeDigitCode code;
	std::cout << "Enter a three-digit code: ";
	std::cin >> code;
	
	int attempts(0);
	ThreeDigitCode code_attempts;
	
	for(;;)
	{
		++attempts;
		if(code_attempts == code)
			break;
		else
			++code_attempts;
	}

	std::cout << "Code = " << code_attempts << ", it took " << attempts << " attempts.\n";

	return 0;
}