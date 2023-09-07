#include "includes/ScalarConverter.hpp"

int main()
{
	std::string str = " nan ";
	std::string &strRef = str;
	ScalarConverter::convert(strRef);
	
	return 0;
}
