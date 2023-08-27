#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	std::cout << "Enter the string: ";
	std::string str;
	std::getline(std::cin, str);
	str += " ";
	
	std::vector<std::string> reverse_str;
	std::string temp{};
	for(std::size_t i{}; i < str.size(); ++i)
	{
		if(str.c_str()[i] != ' ')
		{
			temp += str[i];
		}
		else
		{
			reverse_str.push_back(temp);
			temp.clear();
		}
	}
	
	std::reverse(reverse_str.begin(), reverse_str.end());
	
	for(const auto &elem : reverse_str)
	{
		std::cout << elem << " ";
	}
	
	std::cout << std::endl;
	
	return 0;
}