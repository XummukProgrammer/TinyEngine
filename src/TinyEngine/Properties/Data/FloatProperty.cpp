#include "FloatProperty.hpp"

namespace TinyEngine::Properties::Data
{
    std::string FloatProperty::ToString() const
    {
        return std::to_string(_value);
    }
}
