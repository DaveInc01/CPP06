#include "includes/ScalarConverter.hpp"

int ScalarConverter::_integer = 0;
char ScalarConverter::_character = 0;



ScalarConverter::ScalarConverter(const ScalarConverter & copy)
{
	if(this != &copy)
		*this = copy;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & other)
{
	if(this != &other)
		*this = other;
	return *this;
}

int check_for_int(std::string & str)
{
	unsigned long i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (-1);
	while(i < str.length())
	{
		if (str[i] >= 0 && str[i] <= 9)
			i++;
		else
			return -1;
	}
	return 0;
}

int ScalarConverter::cast_to_char(std::string & str, type t)
{
	if (t == integer)
	{
		int str_i = stoi(str);
		if (str_i >= 32 && str_i <= 126)
		{
			ScalarConverter::_character = str_i;
			// std::cout << "casted char = " << ScalarConverter::_character << std::endl;
			return (0);
		}
		if (str_i <= 32 && str_i >= 0)
			return (1);
	}
	return (-1);
}

void ScalarConverter::convert(std::string & str)
{
	if (str[0] == 0)
		return ;
	if(check_for_int(str) == 0)
	{
		ScalarConverter::_integer = stoi(str);
		// ScalarConverter::cast_to_char(str, integer);

	}
	int integer = stoi(str);
	std::cout << integer << std::endl;
}

