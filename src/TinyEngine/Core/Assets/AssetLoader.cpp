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
}

TINY_ENGINE_FACTORY_MEMBER_IMPL(TinyEngine::AssetLoader)
