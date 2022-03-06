#include "IntProperty.hpp"

namespace TinyEngine::Properties::Data
{
    std::string IntProperty::ToString() const
    {
        return std::to_string(_value);
    }
}
