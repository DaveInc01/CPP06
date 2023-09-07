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

void ScalarConverter::print_data(int displayable)
{
	if (displayable == -1)
		std::cout << "char: Non displayable\n";
	else if (displayable == 0) 
		std::cout << "char: impossible\n";
	else
		std::cout	<< "char: '" << ScalarConverter::_character <<"'\n";
	std::cout 	<< "int: "	 << ScalarConverter::_integer << std::endl
				<< "float: " << ScalarConverter::_float << std::endl
				<< "double: "<< ScalarConverter::_double << std::endl;
}

void	ScalarConverter::cast_from_int(std::string &str)
{
	int tmp = stoi(str);
	int displayable;
	//casting int->char
	if (tmp >= 32 && tmp <= 127)
	{
		ScalarConverter::_character = static_cast<char> (tmp);
		displayable = 0;
		std::cout << ScalarConverter::_character << std::endl;
	}
	else if (tmp >= 0 && tmp <= 31)
		displayable = 1;
	else
		displayable = -1;
	//casting int->double and float
	ScalarConverter::_double = static_cast<double> (tmp);
	ScalarConverter::_float = static_cast<float> (tmp);
	print_data(displayable);
}

int check_validation(std::string & str)
{
	unsigned long i = 0;
	if (!str[i])
		return (-1);

	// check is speial?
	std::string spec_literals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	int length = sizeof(spec_literals) / sizeof(spec_literals[0]);
	if (str_in_arr(str, spec_literals, length) == 0)
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
}

