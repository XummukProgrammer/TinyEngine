#include "LinkAsset.hpp"

#include <TinyEngine/Core/Assets/AssetFile.hpp>

namespace TinyEngine
{
	void LinkAsset::OnAssetLoad()
	{
		AssetFile assetFile;
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, _filePath, &assetFile);
		assetFile.Load();
	}
}
