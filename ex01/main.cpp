#include "includes/Serializer.hpp"

int main()
{
    Data* point = new Data();
    point->x = 20;
    point->y = 30;
    Data* sec_point = new Data();
    uintptr_t int_point = Serializer::serialize(point);
    std::cout << "Serialized - " << int_point << std::endl;
    delete sec_point;
    sec_point = Serializer::deserialize(int_point);
    point->x = 1;
    point->y = 2;
    std::cout << "DeSerialized - " << sec_point << std::endl;
    delete point;
    return 0;
}