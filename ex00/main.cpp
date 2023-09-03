#include "includes/ScalarConverter.hpp"


int main()
{
	std::string str = "68";
	std::string &strRef = str;
	ScalarConverter::convert(strRef);
	return 0;
}
