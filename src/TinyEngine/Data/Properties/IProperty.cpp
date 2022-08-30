#include "IProperty.hpp"

namespace TinyEngine
{
	PropertyData::PropertyData(std::string_view name, std::string_view description)
		: _name(name)
		, _description(description)
	{
	}

	IProperty::IProperty(std::string_view name, std::string_view description)
		: PropertyData(name, description)
	{
	}
}
