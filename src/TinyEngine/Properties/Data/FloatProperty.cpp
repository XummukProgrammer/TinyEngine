#include "FloatProperty.hpp"

namespace TinyEngine::Properties::Data
{
    std::string FloatProperty::ToString() const
    {
        return std::to_string(_value);
    }

    std::string FloatProperty::GetType() const
    {
        return "float";
    }

    void FloatProperty::SaveToFile(pugi::xml_node& node)
    { 
        auto&& attr = node.append_attribute("value");
		attr.set_value(_value);
    }

    void FloatProperty::LoadFromFile(pugi::xml_node& node)
    {
        auto&& attr = node.attribute("value");
		_value = attr.as_float();
    }
}
