#include <iostream>
#include <string>

bool isIcecreamSandwich(const std::string &str)
{
	if(str.size() < 3)
		return false;

	bool IceSandwich(true);
	char first_symbol(str.c_str()[0]);
	char another_symbol('\0');
	std::size_t max_index = str.size() - 1;

	std::size_t i{};
	for(; i < str.size() / 2; ++i, --max_index)
	{
		if(!another_symbol)
		{
			if(str.c_str()[i] == first_symbol && str[i] == str[max_index])
			{
				continue;
			}
			else if((str.c_str()[i] != first_symbol) && str[i] == str[max_index])
			{
				another_symbol = str.c_str()[i];
			}
			else if(str[i] != str[max_index])
			{
				IceSandwich = false;
				break;
			}
		}
		else
		{
			if(str.c_str()[i] == another_symbol && str[i] == str[max_index])
			{
				continue;
			}
			else if(str.c_str()[i] != another_symbol)
			{
				IceSandwich = false;
				break;
			}
		}
	}

	if(IceSandwich && ((str.size()%i) != 0))
	{
		if(another_symbol)
		{
			if(str[i] != another_symbol)
				IceSandwich = false;
		}
		else if(str[i] == first_symbol)
			IceSandwich = false;
	}

	return IceSandwich;
}

int main()
{
	std::string str{"AbbAbb"};
	std::cout << std::boolalpha << isIcecreamSandwich(str) << "\n";

	return 0;
}