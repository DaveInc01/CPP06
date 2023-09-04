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

int check_validation(std::string & str)
{
	unsigned long i = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	std::string spec_literals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	// check is it from array or not and return enum of special type
	if (!str[i])
		return (-1);
	while(i < str.length())
	{
		if (str[i] >= 48 && str[i] <= 57)
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
	str = trim_white_space(str);
	if(check_validation(str) == 0)
	{
		try {
			ScalarConverter::_integer = stoi(str);
			std::cout << "class _integer is " << ScalarConverter::_integer << std::endl;
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Invalid argument: " << e.what() << std::endl;
			return ;
		}
		catch (const std::out_of_range& e) {
			std::cerr << "Out of range: " << e.what() << std::endl;
			return ;
    	}

		// ScalarConverter::cast_to_char(str, integer);

	}
	int integer = stoi(str);
	std::cout << integer << std::endl;
}

