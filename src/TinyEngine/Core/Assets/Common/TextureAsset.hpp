#ifndef _TEXTURE_ASSET_HEADER_
#define _TEXTURE_ASSET_HEADER_

#include <TinyEngine/Core/Assets/Asset.hpp>

namespace TinyEngine
{
	class TextureAsset final : public Asset
	{
		TINY_ENGINE_META_CLASS_DERIVED_BEGIN(TextureAsset, Asset)
		{
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_filePath, "FilePath", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		TextureAsset() = default;
		~TextureAsset() = default;

	public:
		void OnAssetLoad() override;

	private:
		std::string _filePath;
	};
}

#endif // _TEXTURE_ASSET_HEADER_
