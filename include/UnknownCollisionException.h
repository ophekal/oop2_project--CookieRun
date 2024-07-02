#include <stdexcept>
#include <typeinfo>
#include <string>

class UnknownCollisionException : public std::runtime_error
{
public:
    UnknownCollisionException(const std::type_info& type1, const std::type_info& type2)
        : std::runtime_error("Unknown collision between " + std::string(type1.name()) + " and " + std::string(type2.name()))
    {}
};
