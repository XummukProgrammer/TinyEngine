#ifndef _RESOURCES_HEADER_
#define _RESOURCES_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Singleton.hpp>

#include <map>
#include <string>

namespace TinyEngine
{
	class Resources final : public Singleton<Resources>
	{
	public:
		Resources() = default;
		~Resources() = default;

	public:
		void AddResource(std::string_view id, const ResourceSharedPtr& resource);
		bool HasResource(std::string_view id) const;
		ResourceSharedPtr GetBaseResource(std::string_view id) const;
		template<typename T> std::shared_ptr<T> GetResource(std::string_view id) const;

	private:
		std::map<std::string, ResourceSharedPtr> _resources;
	};

	template<typename T>
	std::shared_ptr<T> Resources::GetResource(std::string_view id) const
	{
		if (auto resource = GetBaseResource(id))
		{
			return std::dynamic_pointer_cast<T>(resource);
		}
		return nullptr;
	}
}

#endif // _RESOURCES_HEADER_
