#include "includes/ScalarConverter.hpp"

int ScalarConverter::_integer = 0;
char ScalarConverter::_character = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;



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

void	ScalarConverter::cast_from_int(std::string &str)
{
	int tmp = stoi(str);
	if (tmp >= 32 && tmp <= 127)
	{
		ScalarConverter::_character = static_cast<char> (tmp);
		std::cout << ScalarConverter::_character << std::endl;
	}
}

// int ScalarConverter::cast_to_char(std::string & str, type t)
// {
// 	if (t == int_e)
// 	{
// 		int str_i = stoi(str);
// 		if (str_i >= 32 && str_i <= 126)
// 		{
// 			ScalarConverter::_character = str_i;
// 			// std::cout << "casted char = " << ScalarConverter::_character << std::endl;
// 			return (0);
// 		}
// 		if (str_i <= 32 && str_i >= 0)
// 			return (1);
// 	}
// 	return (-1);
// }

int check_validation(std::string & str)
{
	unsigned long i = 0;
	if (!str[i])
		return (-1);

	// check is speial?
	std::string spec_literals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	std::cout << "sizeof arr* is " << sizeof(spec_literals) << std::endl;
	if (str_in_arr(str, spec_literals) == 0)
		return (special_e);
	//check is int, float or double?
	int str_type = check_is_number(str);
	if (str_type != -1)
		return (str_type);
	str_type = check_is_char(str);
	if (str_type != -1)
		return (char_e);
	return -1;
}

void ScalarConverter::convert(std::string & str)
{
	if (str[0] == 0)
		return ;
	str = trim_white_space(str);
	int str_type = check_validation(str);
	switch (str_type)
	{
	case int_e:
	{
		ScalarConverter::cast_from_int(str);
		std::cout << "type is integer" << std::endl;
		break;
	}
	case char_e:
	{
		std::cout << "type is character_e" << std::endl;
		break;
	}
	case double_e:
	{
		std::cout << "type is double_e" << std::endl;
		break;
	}
	case float_e:
	{
		std::cout << "type is float_e" << std::endl;
		break;
	}
	case special_e:
	{
		std::cout << "type is special_e" << std::endl;
		break;
	}
	default:
		std::cout << "The unknown type\nreturn type: " << str_type << std::endl;
	}



	// if(check_validation(str) == 0)
	// {
	// 	try {
	// 		ScalarConverter::_integer = stoi(str);
	// 		std::cout << "class _integer is " << ScalarConverter::_integer << std::endl;
	// 	}
	// 	catch (const std::invalid_argument& e) {
	// 		std::cerr << "Invalid argument: " << e.what() << std::endl;
	// 		return ;
	// 	}
	// 	catch (const std::out_of_range& e) {
	// 		std::cerr << "Out of range: " << e.what() << std::endl;
	// 		return ;
    // 	}
	// 	// ScalarConverter::cast_to_char(str, integer);
	// }
	// int integer = stoi(str);
	// std::cout << integer << std::endl;
}

