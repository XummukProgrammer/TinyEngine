#include "StringProperty.hpp"

namespace TinyEngine::Properties::Data
{
    std::string StringProperty::ToString() const
    {
        return _value;
    }
}
