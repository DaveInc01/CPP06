#include "./includes/Serializer.hpp"

Serializer::Serializer(const Serializer & copy)
{
	if(this != &copy)
		*this = copy;
}

Serializer & Serializer::operator=(const Serializer & other)
{
	if(this != &other)
		*this = other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t x;
    x = reinterpret_cast <uintptr_t> (ptr);
    return (x);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* x;
    x = reinterpret_cast <Data*> (raw);
    return (x);
}