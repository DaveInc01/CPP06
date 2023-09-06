#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <iostream>
#include <string>
#include <array>


enum type {
	int_e,
	char_e,
	double_e,
	float_e,
	special_e
};

class ScalarConverter
{
public:
	ScalarConverter(){};
	ScalarConverter( const ScalarConverter &);
	ScalarConverter & operator=(const ScalarConverter &);
	~ScalarConverter(){};
public:
	static void 	convert(std::string &);
	static 	void	cast_from_char(std::string &);
	static	void	cast_from_int(std::string &);
	static 	void	cast_from_float(std::string &);
	static	void	cast_from_double(std::string &);
private:
	static char	_character;
	static int 	_integer;
	static float	_float;
	static double	_double;
};

std::string trim_white_space(const std::string& str);
int str_in_arr(std::string str, std::string arr[]);
int check_is_number(std::string str);
int check_is_char (std::string str);

#endif
