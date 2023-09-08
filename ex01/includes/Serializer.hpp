#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

struct Data
{
	int x;
	int y;
};

class Serializer
{
	Serializer(){};
	Serializer( const Serializer &);
	Serializer & operator=(const Serializer &);
	~Serializer(){};
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif