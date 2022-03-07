#include "IntProperty.hpp"

namespace TinyEngine::Properties::Data
{
    std::string IntProperty::ToString() const
    {
        return std::to_string(_value);
    }

    void IntProperty::SaveToFile(pugi::xml_node& node)
    { 
        auto&& attr = node.append_attribute("value");
		attr.set_value(_value);
    }

    void IntProperty::LoadFromFile(pugi::xml_node& node)
    { 
        auto&& attr = node.attribute("value");
		_value = attr.as_int();
    }
}
