#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>
#include <iomanip>
#include <cmath>
#include <algorithm>

#define UTF8_encoded_file	1						//Indicates that the source file is encoded in utf8 
													//(1 if yes, and 0 if no (i.e. if the file encoding is in ANSI)).

#if defined (_WIN32) && UTF8_encoded_file
#include <windows.h>
#include <vector>
#define _TBA UTF8_to_CP1251
#define _8UTF CP1251_to_UTF8
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

std::string CP1251_to_UTF8(const std::string &cp1251)
{
	if(!cp1251.empty())
	{
		int chlen = MultiByteToWideChar(1251, 0, cp1251.c_str(), -1, NULL, 0);
		if(chlen > 0 && chlen != 0xFFFD)
		{
			std::vector<wchar_t> wbuf(static_cast<std::size_t>(chlen));
			MultiByteToWideChar(1251, 0, cp1251.c_str(), -1, &wbuf[0], chlen);
			int chForChar = WideCharToMultiByte(CP_UTF8, 0, &wbuf[0], -1, NULL, 0, 0, 0);
			std::vector<char> buf(static_cast<std::size_t>(chForChar));
			WideCharToMultiByte(CP_UTF8, 0, &wbuf[0], -1, &buf[0], chForChar, 0, 0);
			return std::string(&buf[0]);
		}
	}
	return std::string();
}
#else
#define _TBA
#define _8UTF
#endif

class Students
{
		std::string m_student;
		int m_mathematics;
		int m_physics;
		int m_informatics;

	public:
		Students()
			: m_student{}, m_mathematics{}, m_physics{}, m_informatics{}
		{
		}

		double averageScore() const
		{
			double avSc = (m_mathematics + m_physics + m_informatics) / 3.0;
			avSc = std::round(avSc * 100) / 100;

			return avSc;
		}

		bool operator < (const Students &obj)
		{
			return this->averageScore() < obj.averageScore();
		}

		struct DescendingSorting
		{
			bool operator()(const Students &obj1, const Students &obj2)
			{
				return obj1.averageScore() > obj2.averageScore();
			}
		};

		friend std::ifstream& operator>>(std::ifstream &inf, Students &obj);
		friend std::ostream& operator<<(std::ostream &out, const Students &obj);
};

std::ifstream& operator>>(std::ifstream &inf, Students &obj)
{
	std::getline(inf, obj.m_student, ',');
	inf >> obj.m_mathematics >> obj.m_physics >> obj.m_informatics;
	obj.m_student = _TBA(obj.m_student);

	return inf;
}

std::ostream& operator<<(std::ostream &out, const Students &obj)
{
	out << obj.m_student << _TBA(" - средний балл: ");
	out << std::fixed << std::setprecision(2) << obj.averageScore();

	return out;
}

int main()
{
#if defined (_WIN32)
	std::system("chcp 1251 > NUL");
#endif

	//it is assumed that the text file is encoded in utf8 (with or without BOM)
	std::ifstream inf("ch7ex3_input_data.txt");

	std::vector<Students> readFS;

	if(!inf)
	{
		std::cerr << _TBA("Не удается открыть файл input_data.txt\n");
		return 0;
	}
	else
	{
		//offset of the file pointer if the text file is saved in utf8 format with BOM
		char c1, c2, c3;
		inf >> c1 >> c2 >> c3;
		if(!(static_cast<int>(c1) == -17 && static_cast<int>(c2) == -69
		        && static_cast<int>(c3) == -65))
		{
			inf.seekg(0, std::ios::beg);
		}

		int countStudents(0);
		inf >> countStudents;
		
		if (countStudents)
		{
			for(int i{1}; i <= countStudents; ++i)
			{
				Students st;
				inf >> st;
				readFS.push_back(std::move(st));
			}
		}
		else
		{
			std::cerr << _TBA("Не удалось прочитать количество записей.\n");
			return 0;
		}
	}

	std::sort(readFS.begin(), readFS.end(), Students::DescendingSorting());

	for(const auto &elem : readFS)
	{
		std::cout << elem << "\n";
	}

	return 0;
}