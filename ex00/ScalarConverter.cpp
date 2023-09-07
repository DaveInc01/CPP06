#include "includes/ScalarConverter.hpp"

int ScalarConverter::_integer = 0;
char ScalarConverter::_character = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;
std::string ScalarConverter::spec_literals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};


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

void ScalarConverter::print_data(int displayable, int dot)
{
	if (displayable == 1)
		std::cout << "char: Non displayable\n";
	else if (displayable == -1) 
		std::cout << "char: impossible\n";
	else
		std::cout	<< "char: '" << ScalarConverter::_character <<"'\n";
	if (dot)
		std::cout 	<< "int: "	 << ScalarConverter::_integer << std::endl
					<< "float: " << ScalarConverter::_float << ".0f" << std::endl
					<< "double: "<< ScalarConverter::_double << ".0" << std::endl;
	else
		std::cout 	<< "int: "	 << ScalarConverter::_integer << std::endl
					<< "float: " << ScalarConverter::_float << "f" << std::endl
					<< "double: "<< ScalarConverter::_double << std::endl;
}

void ScalarConverter::cast_from_char(std::string &str)
{
	char tmp = str[0];
	ScalarConverter::_character = static_cast <char> (tmp);
	ScalarConverter::_integer = static_cast <int> (tmp);
	ScalarConverter::_double = static_cast <double> (tmp);
	ScalarConverter::_float = static_cast <float> (tmp);
	int displayable = is_displayable(ScalarConverter::_integer);
	print_data(displayable, 1);
}

void	ScalarConverter::cast_from_int(std::string &str)
{
	try {
		int tmp = stoi(str);
		int displayable = is_displayable(tmp);	
		ScalarConverter::_character = static_cast<char> (tmp);
		ScalarConverter::_double = static_cast<double> (tmp);
		ScalarConverter::_float = static_cast<float> (tmp);
		ScalarConverter::_integer = static_cast<int> (tmp);
		print_data(displayable, 1);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void ScalarConverter::cast_from_float(std::string &str)
{
	try{
		float tmp = std::stof(str);
		ScalarConverter::_double = static_cast<double> (tmp);
		ScalarConverter::_float = static_cast<float> (tmp);
		ScalarConverter::_integer = static_cast<int> (tmp);
		ScalarConverter::_character = static_cast<char> (ScalarConverter::_integer);
		int displayable = is_displayable(ScalarConverter::_integer);
		print_data(displayable, 0);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void ScalarConverter::cast_from_double(std::string &str)
{
	try{
		double tmp = std::stod(str);
		ScalarConverter::_double = static_cast<double> (tmp);
		ScalarConverter::_float = static_cast<float> (tmp);
		ScalarConverter::_integer = static_cast<int> (tmp);
		ScalarConverter::_character = static_cast<char> (ScalarConverter::_integer);
		int displayable = is_displayable(ScalarConverter::_integer);
		print_data(displayable, 0);
	}
	catch(std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

void ScalarConverter::cast_from_special(std::string &str)
{
	int length = sizeof(ScalarConverter::spec_literals) / sizeof(ScalarConverter::spec_literals[0]);
	int place = place_in_arr(str, ScalarConverter::spec_literals, length);
	if (place == -1)
		return ;
	std::cout << "char: impossible\nint: impossible\n";
	if(place < 3)
	{
		std::cout << "float: " << ScalarConverter::spec_literals[place] << std::endl
				  << "double: " << ScalarConverter::spec_literals[place + 3] << std::endl;
	}
	else
	{
		std::cout << "float: " << ScalarConverter::spec_literals[place - 3] << std::endl
				  << "double: " << ScalarConverter::spec_literals[place] << std::endl;
	}
}

int ScalarConverter::check_validation(std::string & str)
{
	unsigned long i = 0;
	if (!str[i])
		return (-1);

	// check is speial?
	int length = sizeof(ScalarConverter::spec_literals) / sizeof(ScalarConverter::spec_literals[0]);
	if (str_in_arr(str, ScalarConverter::spec_literals, length) == 0)
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
	if (str.length() != 1)
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
		ScalarConverter::cast_from_char(str);
		break;
	}
	case double_e:
	{
		ScalarConverter::cast_from_double(str);
		break;
	}
	case float_e:
	{
		ScalarConverter::cast_from_float(str);
		break;
	}
	case special_e:
	{
		ScalarConverter::cast_from_special(str);
		break;
	}
	default:
		std::cout << "The unknown type" << std::endl;
	}
}

