#include "AssetLoader.hpp"

namespace TinyEngine
{
	void AssetLoader::OnLoad()
	{
		Create();
	}

	void AssetLoader::Create()
	{
		SerializationUtils::LoadRootFromFile(SerializationUtils::ArchiveFormat::Xml, _path, &_source);
		_source.GetAsset()->OnLoad();
	}
}
