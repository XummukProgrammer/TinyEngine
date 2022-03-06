#include "Properties.hpp"

#include <TinyEngine/Properties/Data/IntProperty.hpp>

namespace TinyEngine::Properties
{
	void Properties::SetProperty(std::string_view key, IPropertyPtr&& property)
	{ 
		_properties[std::string{key}] = std::move(property);
	}

	Properties::IPropertyPtr Properties::GetProperty(std::string_view key) const
	{
		auto it = _properties.find(std::string{key});

		if (it != _properties.end())
		{
			return it->second;
		}

		return nullptr;
	}

	void Properties::SetIntProperty(std::string_view key, int value)
	{ 
		if (auto property = GetIntProperty(key))
		{
			property->SetValue(value);
			return;
		}

		auto property = std::make_shared<Data::IntProperty>();
		property->SetValue(value);
		SetProperty(key, std::move(property));
	}

	Properties::IntPropertyPtr Properties::GetIntProperty(std::string_view key) const
	{
		if (auto property = GetProperty(key))
		{
			if (auto intProperty = std::dynamic_pointer_cast<Data::IntProperty>(property))
			{
				return intProperty;
			}
		}

		return nullptr;
	}

	int Properties::GetIntProperty(std::string_view key, int default) const
	{
		if (auto property = GetIntProperty(key))
		{
			return property->GetValue();
		}

		return default;
	}
}
