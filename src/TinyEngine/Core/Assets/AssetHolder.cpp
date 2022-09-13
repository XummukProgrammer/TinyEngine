#include "AssetHolder.hpp"

namespace TinyEngine
{
	void AssetHolder::OnAssetLoad()
	{
		for (const auto& asset : _assets)
		{
			asset->OnAssetLoad();
		}
	}

	TINY_ENGINE_META_FACTORY_IMPL(AssetHolder)
}
