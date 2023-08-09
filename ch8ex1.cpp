#include <iostream>
#include <string>
#include <string_view>

#define UTF8_encoded_file	1						//Indicates that the source file is encoded in utf8 
//(1 if yes, and 0 if no (i.e. if the file encoding is in ANSI)).

#if defined (_WIN32) && UTF8_encoded_file
#include <windows.h>
#include <vector>
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

///////////////////////////////////////////////////////////////////////////

std::string correctFormWord (int penny)
{
	if(penny >=11 && penny <= 19)
		return _TBA("копеек");
		
	std::string_view lastNumber{std::to_string(penny)};
	if(lastNumber.length() > 1)
	{
		lastNumber.remove_prefix(1);
	}
	
	if(lastNumber == "1")
		return _TBA("копейка");
	
	if(lastNumber == "2" || lastNumber == "3" || lastNumber == "4")
		return _TBA("копейки");
	
	return _TBA("копеек");
}

/////////////////////////////////////////////////////////////////////////////

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if (std::cin.fail() || (!(value >= 1 && value <= 99)))
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

/////////////////////////////////////////////////////////////////////////////

int main()
{
#if defined (_WIN32)
	std::system("chcp 1251 > NUL");			//In the windows console, Cyrillic works only in ANSI encoding
#endif
	
	std::cout << _TBA("Введите число из диапазона от 1 до 99: ");
	int number{inputValue()};
	
	std::cout << number << " " << correctFormWord(number) << "\n";

	return 0;
}