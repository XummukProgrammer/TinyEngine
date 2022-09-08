#include "AssetLoader.hpp"

namespace TinyEngine
{
	void AssetLoader::OnAssetLoad()
	{
		Create();
	}

	void AssetLoader::Create()
	{
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, _path, &_source);
		_source.GetAsset()->OnAssetLoad();
	}

	TINY_ENGINE_META_FACTORY_IMPL(AssetLoader)
}
