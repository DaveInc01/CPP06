#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <iostream>
#include <string>

enum type {
	integer,
	character,
	boolean,
	floating
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
	static int		cast_to_char(std::string &, type t);
	static int		cast_to_int(std::string &, type t);
	static float	cast_to_float(std::string &, type t);
	static double	cast_to_double(std::string &, type t);
private:
	static char	_character;
	static int 	_integer;
	// static float	_float;
	// static double	_double;
};

#endif
