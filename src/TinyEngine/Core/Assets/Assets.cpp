#include "Assets.hpp"

#include <TinyEngine/Core/Data/Factory.hpp>
#include <TinyEngine/Core/Data/Serialization/Serialization.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>

namespace TinyEngine
{
	void Assets::AddAsset(std::string_view id, const AssetSharedPtr& asset)
	{
		_assets[std::string{id}] = asset;
	}

	bool Assets::HasAsset(std::string_view id) const
	{
		return GetBaseAsset(id) != nullptr;
	}

	AssetSharedPtr Assets::GetBaseAsset(std::string_view id) const
	{
		auto it = _assets.find(std::string{id});
		if (it != _assets.end())
		{
			return it->second;
		}
		return nullptr;
	}

	void AssetsUtils::CreateAssetFile(std::string_view filePath, std::string_view type)
	{
		auto asset = Factory::GetInstance()->CreateBase(type);
		SerializationUtils::SaveRootToFile(ArchiveFormat::Xml, filePath, asset.get());
	}
}
