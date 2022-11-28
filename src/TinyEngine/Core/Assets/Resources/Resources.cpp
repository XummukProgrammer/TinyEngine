#include "Resources.hpp"

#include <TinyEngine/Core/Assets/Resources/Resource.hpp>

namespace TinyEngine
{
	void Resources::AddResource(std::string_view id, const ResourceSharedPtr& resource)
	{
		_resources[std::string{id}] = resource;
	}

	bool Resources::HasResource(std::string_view id) const
	{
		return GetBaseResource(id) != nullptr;
	}

	ResourceSharedPtr Resources::GetBaseResource(std::string_view id) const
	{
		auto it = _resources.find(std::string{id});
		if (it != _resources.end())
		{
			return it->second;
		}
		return nullptr;
	}
}
