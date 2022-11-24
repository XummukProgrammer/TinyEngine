#ifndef _LINK_ASSET_HEADER_
#define _LINK_ASSET_HEADER_

#include <TinyEngine/Core/Assets/Asset.hpp>

#include <string>

namespace TinyEngine
{
	class LinkAsset final : public Asset
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(LinkAsset, Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_filePath, "FilePath", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		LinkAsset() = default;
		~LinkAsset() = default;

	public:
		void OnAssetLoad() override;

	private:
		std::string _filePath;
	};
}

#endif // _LINK_ASSET_HEADER_
