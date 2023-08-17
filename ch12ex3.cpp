#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <string_view>
#include <iomanip>

//////////////////////////////////////////////////////////////////////////////////////////////////////////
#define UTF8_encoded_file	1						//Indicates that the source file is encoded in utf8 
//(1 if yes, and 0 if no (i.e. if the file encoding is in ANSI)).

#if defined (_WIN32) && UTF8_encoded_file
#include <windows.h>
#include <vector>
#include <string>
#define _TBA UTF8_to_CP1251
std::string UTF8_to_CP1251(const std::string &utf8)
{
	if(!utf8.empty())
	{
		int wchlen = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, NULL, 0);
		if(wchlen > 0 && wchlen != 0xFFFD)
		{
			std::vector<wchar_t> wbuf(static_cast<std::size_t>(wchlen));
			MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, &wbuf[0], wchlen);
			std::vector<char> buf(static_cast<std::size_t>(wchlen));
			WideCharToMultiByte(1251, 0, &wbuf[0], -1, &buf[0], wchlen, 0, 0);
			return std::string(&buf[0]);
		}
	}
	return std::string();
}
#else
#define _TBA
#endif
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if (std::cin.fail() || (!(value >= 1 && value <= 3)))
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////
class Human
{
	protected:
		std::string m_name{};
		int m_age{};
		static const std::string m_globalName[];

	public:
		Human()
		{
			auto myGenerate =
			    [](int start, int end) -> int
			{
				std::random_device rd;
				std::mt19937 rnd(rd());
				std::uniform_int_distribution<int> distrib(start, end);
				return distrib(rnd);
			};

			int indexName = myGenerate(0, 9);

			m_name = m_globalName[indexName];
			m_age = myGenerate(20, 40);
		}

		const std::string& getName() const
		{
			return m_name;
		}

		int getAge() const
		{
			return m_age;
		}

		const std::string correctFormWord () const
		{
			if(m_age >=11 && m_age <= 19)
				return _TBA("лет");

			std::string_view lastNumber{std::to_string(m_age)};
			if(lastNumber.length() > 1)
			{
				lastNumber.remove_prefix(1);
			}

			if(lastNumber == "1")
				return _TBA("год");

			if(lastNumber == "2" || lastNumber == "3" || lastNumber == "4")
				return _TBA("года");

			return _TBA("лет");
		}

		virtual void sayHello(const Human&) const = 0;

		virtual void tellYourself() const = 0;

		virtual ~Human()
		{
		}
};

class Formalist : public Human
{
	public:
		Formalist()
		{
		}

		virtual ~Formalist()
		{
		}

		virtual void sayHello(const Human &obj) const override
		{
			std::cout << std::setw(10) << m_name << _TBA(":\tЗдравствуйте, ") << obj.getName() << "!";
		}

		virtual void tellYourself() const override
		{
			std::cout << _TBA("Меня зовут ") << m_name << _TBA(", мой возраст ");
			std::cout << m_age << " " << correctFormWord() << _TBA(" и я формалист.");
		}
};

class Informal : public Human
{
	public:
		Informal()
		{
		}

		virtual ~Informal()
		{
		}

		virtual void sayHello(const Human &obj) const override
		{
			std::cout << std::setw(10) << m_name << _TBA(":\tПривет, ") << obj.getName() << "!";
		}

		virtual void tellYourself() const override
		{
			std::cout << _TBA("Меня зовут ") << m_name << _TBA(", мой возраст ");
			std::cout << m_age << " " << correctFormWord() << _TBA(" и я неформал.");
		}
};

class Realist : public Human
{
	public:
		Realist()
		{
		}

		virtual ~Realist()
		{
		}

		virtual void sayHello(const Human &obj) const override
		{
			if(obj.getAge() <= m_age + 5)
				std::cout << std::setw(10) << m_name << _TBA(":\tПривет, ") << obj.getName() << "!";
			else
				std::cout << std::setw(10) << m_name << _TBA(":\tЗдравствуйте, ") << obj.getName() << "!";
		}

		virtual void tellYourself() const override
		{
			std::cout << _TBA("Меня зовут ") << m_name << _TBA(", мой возраст ");
			std::cout << m_age << " " << correctFormWord() << _TBA(" и я реалист.");
		}
};

const std::string Human::m_globalName[] {_TBA("Александр"), _TBA("Андрей"),
	      _TBA("Анастасия"), _TBA("Ирина"), _TBA("Наталья"), _TBA("Павел"),
	      _TBA("Роман"), _TBA("Светлана"), _TBA("Сергей"), _TBA("Татьяна")
};

int main()
{
#if defined (_WIN32)
	std::system("chcp 1251 > NUL");
#endif

	Human *human[5];

	for(int i = 0; i < 5; ++i)
	{
		std::cout << _TBA("\nВыберите тип лисности (1 - формалист, 2 - неформал, 3 - реалист): ");

		int personality_type(inputValue());

		if(personality_type == 1)
			human[i] = new Formalist;
		else if(personality_type == 2)
			human[i] = new Informal;
		else
			human[i] = new Realist;
	}

	for(int i = 0; i < 5; ++i)
	{
		std::cout << "\n";
		human[i]->tellYourself();
		std::cout << "\n";
	}

	for(int i = 0; i < 4; ++i)
	{
		for(int j = i + 1; j < 5; ++j)
		{
			std::cout.fill('-'); 
			std::cout << "\n";
			human[i]->sayHello(*human[j]);
			std::cout << "\n";
			human[j]->sayHello(*human[i]);
			std::cout << "\n\n";
		}
	}

	for(int i = 0; i < 5; ++i)
		delete human[i];

	return 0;
}