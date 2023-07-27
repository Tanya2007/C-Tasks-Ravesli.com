#include <iostream>
#include <string_view>
#include <string>

#if defined (_WIN32)
#include <windows.h>

void beepDot()
{
	Beep(800, 150);
}

void beepDash()
{
	Beep(800, 450);
}

void sleepWords()
{
	Sleep(1050);
}

void sleepLetters()
{
	Sleep(450);
}

#else
//for systems other than windows, you need to write functions
//beepDot(), beepDash(), sleepWords(), sleeoLetters()
#endif

std::string_view returnMorseCode(char ch)
{
	switch(ch)
	{
		case 'A':
		case 'a':
			return ".-";

		case 'B':
		case 'b':
			return "-...";

		case 'C':
		case 'c':
			return "-.-.";

		case 'D':
		case 'd':
			return "-..";

		case 'E':
		case 'e':
			return ".";

		case 'F':
		case 'f':
			return "..-.";

		case 'G':
		case 'g':
			return "--.";

		case 'H':
		case 'h':
			return "....";

		case 'I':
		case 'i':
			return "..";

		case 'J':
		case 'j':
			return ".---";

		case 'K':
		case 'k':
			return "-.-";

		case 'L':
		case 'l':
			return ".-..";

		case 'M':
		case 'm':
			return "--";

		case 'N':
		case 'n':
			return "-.";

		case 'O':
		case 'o':
			return "---";

		case 'P':
		case 'p':
			return ".--.";

		case 'Q':
		case 'q':
			return "--.-";

		case 'R':
		case 'r':
			return ".-.";

		case 'S':
		case 's':
			return "...";

		case 'T':
		case 't':
			return "-";

		case 'U':
		case 'u':
			return "..-";

		case 'V':
		case 'v':
			return "...-";

		case 'W':
		case 'w':
			return ".--";

		case 'X':
		case 'x':
			return "-..-";

		case 'Y':
		case 'y':
			return "-.--";

		case 'Z':
		case 'z':
			return "--..";

		case '1':
			return ".----";

		case '2':
			return "..---";

		case '3':
			return "...--";

		case '4':
			return "....-";

		case '5':
			return ".....";

		case '6':
			return "-....";

		case '7':
			return "--...";

		case '8':
			return "---..";

		case '9':
			return "----.";

		case '0':
			return "-----";
	}

	return " ";
}

int main()
{
	std::cout << "Enter a string to convert to Morse code: ";
	std::string morseCode{};

	std::getline(std::cin, morseCode);

	for(std::size_t i{}; i < morseCode.length(); ++i)
	{
		if(morseCode.c_str()[i] == ' ')
		{
			sleepWords();
			std::cout << "   ";
		}
		else
		{
			std::string_view morse{returnMorseCode(morseCode.c_str()[i])};

			if(morse != " ")
			{
				for(std::size_t j{}; j < morse.length(); ++j)
				{
					if(morse.data()[j] == '.')
					{
						std::cout << ".";
						beepDot();
					}
					else
					{
						std::cout << "-";
						beepDash();
					}
				}

				sleepLetters();
				std::cout << " ";
			}
		}
	}
	
	return 0;
}