#include "StringProperty.hpp"

namespace TinyEngine::Properties::Data
{
    std::string StringProperty::ToString() const
    {
        return _value;
    }

    std::string StringProperty::GetType() const
    {
        return "string";
    }

    void StringProperty::SaveToFile(pugi::xml_node& node)
    { 
        auto&& attr = node.append_attribute("value");
		attr.set_value(_value.c_str());
    }

    void StringProperty::LoadFromFile(pugi::xml_node& node)
    { 
        auto&& attr = node.attribute("value");
        _value = std::string{attr.as_string()};
    }
}
