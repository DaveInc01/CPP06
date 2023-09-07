#include "includes/ScalarConverter.hpp"

std::string trim_white_space(const std::string& str) {
    size_t start = 0;
    size_t end = str.length() - 1;

    while (start <= end && std::isspace(str[start])) {
        ++start;
    }
    while (end >= start && std::isspace(str[end])) {
        --end;
    }
    return str.substr(start, end - start + 1);
}

int str_in_arr(std::string str, std::string *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == str)
            return 0;
    }
    return (-1);
}

int check_is_number(std::string str)
{
    int is_point = 0;
    int is_float = 0;
    unsigned long i = 0;
    while (str[i] == '-' || str[0] == '+')
        i++;
    while(i < str.length())
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
        else if (str[i] == '.')
        {
            is_point++;
            i++;
        }
        else if (str[i] == 'f' && i == str.length() - 1)
        {
            is_float = 1;
            i++;
        }
		else
			return -1;
	}
    if (is_point == 1 && is_float == 1)
        return (float_e);
    else if (is_point == 1)
        return (double_e);
    else
        return (int_e);
}

int check_is_char (std::string str)
{
    if (str.length() == 1)
    {
        if (str[0] >= 0 && str[0] < 32)
            return (1);
        else if (str[0] >= 32 && str[0] <= 127)
            return (0);
    }
    return -1;
}
