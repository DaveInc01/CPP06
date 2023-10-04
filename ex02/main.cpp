#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"

Base * generate(void)
{
    Base *tmp = NULL;
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int random = std::rand() % 3;
    switch(random)
    {
        case 0:
            return (tmp = new A());
        case 1:
            return(tmp = new B());
        case 2:
            return (tmp = new C());
        default:
            return tmp;
    }
}

void identify(Base* p)
{
    Base * tmpA = p;
    Base * tmpB = p;
    Base * tmpC = p;

    tmpA = dynamic_cast <A *> (p);
    if (tmpA)
        std::cout << "The class type is A\n";
    tmpB = dynamic_cast <B *> (p);
    if (tmpB)
        std::cout << "The class type is B\n";
    tmpC = dynamic_cast <C *> (p);
    if (tmpC)
        std::cout << "The class type is C\n";
}

void identify(Base& p)
{
    Base& tmpA = p;
    Base& tmpB = p;
    Base& tmpC = p;

    try
    {
        tmpB = dynamic_cast <B&> (p);
        std::cout << "The class type is B\n";
    }
    catch (std::bad_cast& e) {}
    try
    {
        tmpA = dynamic_cast <A&> (p);
        std::cout << "The class type is A\n";
    }
    catch (std::bad_cast& e) {}


    try
    {
        tmpC = dynamic_cast <C&> (p);
        std::cout << "The class type is C\n";
    }
    catch (std::bad_cast& e) {}
}


int main()
{
    // Dynamic cast using referance
    A a;
    Base &br = dynamic_cast <Base &>(a);
    identify(br);
    // Dynamic cast usin pointers
    Base *rand = generate();
    identify(rand);
    delete rand;
    return 0;
}
