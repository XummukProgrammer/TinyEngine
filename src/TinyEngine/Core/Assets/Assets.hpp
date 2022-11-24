#ifndef _ASSETS_HEADER_
#define _ASSETS_HEADER_

#include <TinyEngine/Core/Data/Singleton.hpp>
#include <TinyEngine/Core/Forwards.hpp>

#include <map>
#include <string>

namespace TinyEngine
{
	class Assets final : public Singleton<Assets>
	{
	public:
		Assets() = default;
		~Assets() = default;

	public:
		void AddAsset(std::string_view id, const AssetSharedPtr& asset);
		bool HasAsset(std::string_view id) const;
		AssetSharedPtr GetBaseAsset(std::string_view id) const;
		template<typename T> std::shared_ptr<T> GetAsset(std::string_view id) const;

	private:
		std::map<std::string, AssetSharedPtr> _assets;
	};

	template<typename T>
	std::shared_ptr<T> Assets::GetAsset(std::string_view id) const
	{
		if (auto asset = GetBaseAsset(id))
		{
			return std::dynamic_pointer_cast<T>(asset);
		}
		return nullptr;
	}
}

#endif // _ASSETS_HEADER_
