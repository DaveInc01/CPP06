#include "includes/A.hpp"

Base * A::generate(void)
{
    Base * tmp = new A();
    return (tmp);
}

// void A::identify(Base* p)
// {
//     A *tmp = new A();
//     tmp = dynamic_cast <A *> (p);
//     if (tmp)
//     {
//         std::cout << "The object type is Base" << std::endl;
//     }
//     else
//     {
//         std::cout << "The object type is Derived" << std::endl;
//     }
// }