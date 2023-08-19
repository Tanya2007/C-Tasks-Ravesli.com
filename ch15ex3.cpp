#include <iostream>
#include <string>
#include <algorithm>
#include <random>

#define UTF8_encoded_file	1			//Indicates that the source file is encoded in utf8 
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

int main()
{
#if defined (_WIN32)
	std::system("chcp 1251 > NUL");
#endif

	std::cout << _TBA("Введите слово: ");
	std::string word;
	std::cin >> word;
	
	std::string temp{};
	int count(0);
	std::size_t length = word.size();
	std::size_t *indexes = new std::size_t[length];
	
	for(std::size_t i{}; i < length; ++i)
	{
		indexes[i] = i;
	}
	
	while(word != temp)
	{
		temp.clear();
		std::cout << "[" << count << "] ";

		auto rng = std::default_random_engine{};
		std::shuffle(indexes, indexes + length, rng);
		
		for(std::size_t i{}; i < length; ++i)
		{
			std::cout << indexes[i];
			temp.push_back(word[indexes[i]]);
		}
		
		std::cout << " " << temp << "\n";
		++count;
	}
	
	delete [] indexes;
	
	return 0;
}