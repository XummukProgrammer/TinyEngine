﻿#include "Assets.hpp"

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
}
