#include <regex>
#include <string>
#include <iostream>
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
int main()
{
#if defined (_WIN32)
	std::system("chcp 1251 > NUL");
#endif
	std::cout << _TBA("Введите строку: ");
	std::string str;
	std::getline(std::cin, str);

	std::regex rx(_TBA("[^а-яёА-ЯЁ]"));
	std::string fmt("");
	
	std::cout << std::regex_replace(str, rx, fmt) << std::endl;

	return 0;
}