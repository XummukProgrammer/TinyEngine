#include "LinkAsset.hpp"

#include <TinyEngine/Core/Assets/Assets.hpp>
#include <TinyEngine/Core/Data/Factory.hpp>

namespace TinyEngine
{
	void LinkAsset::OnAssetLoad()
	{
		_asset = Factory::GetInstance()->Create<Asset>(_type);
		if (!_asset)
		{
			return;
		}

		SerializationUtils::LoadRootFromFile(ArchiveFormat::Xml, _filePath, _asset.get());
		
		if (_asset)
		{
			_asset->OnAssetLoad();
			Assets::GetInstance()->AddAsset(_asset->GetId(), _asset);
		}
	}
}
