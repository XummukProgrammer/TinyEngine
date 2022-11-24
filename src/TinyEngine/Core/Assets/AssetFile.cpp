#include "AssetFile.hpp"

#include <TinyEngine/Core/Assets/Asset.hpp>

namespace TinyEngine
{
	void AssetFile::Load()
	{
		if (_asset)
		{
			_asset->OnAssetLoad();
		}
	}
}
