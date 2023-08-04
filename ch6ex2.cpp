#include <iostream>
#include <string>

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

void sleep(int sl)
{
	Sleep(static_cast<DWORD>(sl));
}

#else
#define _TBA
//for other operating systems, 
//you need to write your own function "sleep(int)"
#endif

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
#if defined (_WIN32)
	std::system("chcp 1251 > NUL");			
#endif
	
	std::string mesaage = _TBA("Привет! Меня зовут Таня!\n");
	std::cout << _TBA("Введите задержку вывода букв сообщения: ");
	int sl(inputValue());
	
	for(std::size_t i{}; i < mesaage.length(); ++i)
	{
		sleep(sl);
		std::cout << mesaage.c_str()[i];
	}
	
	std::cout << "\n";
	
	return 0;
}