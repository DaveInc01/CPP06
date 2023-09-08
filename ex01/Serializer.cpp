#include "./includes/Serializer.hpp"

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

uintptr_t Serializer::serialize(Data* ptr)
{
    try
    {
        uintptr_t x;
        x = static_cast <uintptr_t> (ptr);
    }
}