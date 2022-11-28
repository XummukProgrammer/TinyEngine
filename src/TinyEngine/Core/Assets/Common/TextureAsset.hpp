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
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_isRepeated, "IsRepeated", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_isSmooth, "IsSmooth", "");
			TINY_ENGINE_META_CLASS_DELC_MEMBER_DEFAULT(_isSrgb, "IsSrgb", "");
		}
		TINY_ENGINE_META_CLASS_END

	public:
		TextureAsset() = default;
		~TextureAsset() = default;

	public:
		void OnAssetLoad() override;

	private:
		std::string _filePath;
		bool _isRepeated;
		bool _isSmooth;
		bool _isSrgb;
	};
}

#endif // _TEXTURE_ASSET_HEADER_
