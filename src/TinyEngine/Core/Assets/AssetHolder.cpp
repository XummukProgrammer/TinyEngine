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
}

TINY_ENGINE_FACTORY_MEMBER_IMPL(TinyEngine::AssetHolder)
