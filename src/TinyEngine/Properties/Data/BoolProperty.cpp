#include "BoolProperty.hpp"

namespace TinyEngine::Properties::Data
{
	std::string BoolProperty::ToString() const
	{
		return _value ? "true" : "false";
	}

	std::string BoolProperty::GetType() const
	{
		return "bool";
	}

	void BoolProperty::SaveToFile(pugi::xml_node& node)
	{ 
		auto&& attr = node.append_attribute("value");
		attr.set_value(_value);
	}

	void BoolProperty::LoadFromFile(pugi::xml_node& node)
	{ 
		auto&& attr = node.attribute("value");
		_value = attr.as_bool();
	}
}
