#ifndef _ASSET_FILE_HEADER_
#define _ASSET_FILE_HEADER_

#include <TinyEngine/Core/Forwards.hpp>
#include <TinyEngine/Core/Data/Meta/MetaDefines.hpp>
#include <TinyEngine/Core/Assets/Asset.hpp>

namespace TinyEngine
{
	class AssetFile final : public MetaClass
	{
		TINY_ENGINE_META_CLASS_BEGIN(AssetFile)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_asset, "Asset", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		AssetFile() = default;
		~AssetFile() = default;

	public:
		void Load();

	private:
		AssetSharedPtr _asset;
	};
}

#endif // _ASSET_FILE_HEADER_
