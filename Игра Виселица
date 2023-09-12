#include <iostream>
#include <string>
#include <vector>
#include <random>

#define UTF8_encoded_file	1			//Indicates that the source file is encoded in utf8 
//(1 if yes, and 0 if no (i.e. if the file encoding is in ANSI)).

#if defined (_WIN32) && UTF8_encoded_file
#include <windows.h>
#include <string>
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

	std::cout << _TBA("Добро пожаловать в игру 'Виселица'!\n\n");

	const std::vector<std::string> arrWords = {_TBA("идея"), _TBA("письмо"), _TBA("понятие"),
	                                           _TBA("конкурс"), _TBA("технология"), _TBA("сигарета"),
	                                           _TBA("потребность"), _TBA("земля"), _TBA("песня"),
	                                           _TBA("царь"), _TBA("блок"), _TBA("рабочий"),
	                                           _TBA("сочинение"), _TBA("частность"), _TBA("номер"),
	                                           _TBA("рубль"), _TBA("поведение"), _TBA("участок"),
	                                           _TBA("группа"), _TBA("телевизор"), _TBA("зрение"),
	                                           _TBA("разрешение"), _TBA("система"), _TBA("длина"),
	                                           _TBA("учреждение"), _TBA("академия"), _TBA("вид"),
	                                           _TBA("объединение"), _TBA("фирма"), _TBA("капитан"),
	                                           _TBA("направление"), _TBA("существование"), _TBA("капитал"),
	                                           _TBA("анализ"), _TBA("участие"), _TBA("труд"),
	                                           _TBA("сделка"), _TBA("политика"), _TBA("повышение"),
	                                           _TBA("инструмент")
	                                          };
	                                          
	auto myGenerate =
	    []() -> int
	{
		std::random_device rd;
		std::mt19937 rnd(rd());
		std::uniform_int_distribution<int> distrib(0, 39);
		return distrib(rnd);
	};
	
	const std::string &guessed_word = arrWords[static_cast<std::size_t>(myGenerate())];
	
	std::string guess{};
	for(std::size_t i{}; i < guessed_word.size(); ++i)
	{
		guess += "_";
	}
	
	std::cout << _TBA("Все буквы в слове строчные.\n");
	std::cout << _TBA("В слове ") << guessed_word.size() << _TBA(" букв.\n");
	
	int count = 6;
	while(count && (guessed_word != guess))
	{
		bool guessed_letter = false;
		std::cout << _TBA("\nСлово: ") << guess << "\n";
		std::cout << _TBA("У вас ") << count << _TBA(" попыток.\n");
		std::cout << _TBA("Введите букву: ");
		
		char ch;
		std::cin >> ch;
		
		for(std::size_t i{}; i < guessed_word.size(); ++i)
		{
			if(guessed_word.c_str()[i] == ch)
			{
				guess[i] = guessed_word[i];
				guessed_letter = true;
			}
		}
		
		if(!guessed_letter)
		{
			std::cout << _TBA("Не верно! Такой буквы нет.\n");
			--count;
		}		
	}
	
	if(guessed_word == guess)
	{
		std::cout << _TBA("\nУрааааааа!!!! Вы победили!!!!\n");
	}
	else
	{
		std::cout << _TBA("\nВы проиграли...\n");
	}

	return 0;
}
