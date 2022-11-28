#include "LinkAsset.hpp"

#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Data/Factory.hpp>
#include <TinyEngine/Core/FileSystem.hpp>

#include <string>

namespace TinyEngine
{
	void LinkAsset::OnAssetLoad()
	{
		auto asset = Factory::GetInstance()->Create<Asset>(_type);
		if (!asset)
		{
			return;
		}

		const auto filePath = FileSystem::GetInstance()->BuildPath(DirType::Project, _filePath);
		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, filePath, asset.get(), false);
		
		if (asset)
		{
			asset->SetFilePath(filePath);
			asset->OnAssetLoad();
			Assets::GetInstance()->AddAsset(asset->GetId(), asset);
		}
	}
}
