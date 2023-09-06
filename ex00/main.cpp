#include "includes/ScalarConverter.hpp"


int main()
{
	std::string str = "          42";
	std::string &strRef = str;
	ScalarConverter::convert(strRef);
	return 0;
}
