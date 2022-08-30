#include "Properties.hpp"

#include <TinyEngine/Data/Properties/IProperty.hpp>

namespace TinyEngine
{
	void Properties::AddProperty(IPropertySharedPtr property)
	{
		_properties[property->GetName()] = property;
	}

	IPropertySharedPtr Properties::GetProperty(std::string_view id) const
	{
		auto it = _properties.find(std::string{id});
		if (it != _properties.end())
		{
			return it->second;
		}
		return nullptr;
	}

	void Properties::ForEach(const OnForEach& callback) const
	{
		if (!callback)
		{
			return;
		}

		for (const auto& [ id, property ] : _properties)
		{
			callback(id, property);
		}
	}

	void Properties::LoadFromArchive(InputArchivePtr archive)
	{
		ForEach([archive](std::string_view id, IPropertySharedPtr property)
		{
			property->LoadFromArchive(archive);
		});
	}

	void Properties::SaveToArchive(OutputArchivePtr archive)
	{
		ForEach([archive](std::string_view id, IPropertySharedPtr property)
		{
			property->SaveToArchive(archive);
		});
	}
}
