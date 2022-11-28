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
